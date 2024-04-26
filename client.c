/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:02:46 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/26 10:59:43 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <signal.h>

void	last_send(int pid)
{
	int	c;

	c = 0;
	while (c < 8)
	{
		usleep(400);
		kill(pid, SIGUSR2);
		c++;
	}
	return ;
}

void	sending_bits(int pid, char *str)
{
	size_t	i;
	int		a;
	int		c;

	i = 0;
	while (str[i])
	{
		a = str[i];
		c = 0;
		while (c < 8)
		{
			if (a & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			a >>= 1;
			c++;
			usleep(900);
		}
		i++;
	}
	last_send(pid);
}

void	sig_handler_client(int sig)
{
	(void)sig;
	ft_putstr_fd("Your text has been print succesfully on the server", 1);
}

void	setup_client(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction", 2);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc != 3)
	{
		ft_putstr_fd("You need to put exactly 3 args : ./client PID 'string'",
			2);
		return (-1);
	}
	else
		pid = ft_atoi(argv[1]);
	if (pid < 1)
	{
		ft_putstr_fd("You don't have authorisation to access this PID", 2);
		return (-1);
	}
	setup_client();
	sending_bits(pid, argv[2]);
	pause();
}
