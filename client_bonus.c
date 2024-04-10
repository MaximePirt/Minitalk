/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:51:59 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 22:22:23 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	c = 0;
	while (c < 8)
	{
		usleep(700);
		kill(pid, SIGUSR2);
		c++;
	}
}

void	sig_handler_client(int sig)
{
	(void)sig;
	ft_putstr_fd("\nYour text has been print succesfully on the server", 1);
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
	int pid = 0;
	if (argc < 2)
		return (-1);
	else
		pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (-1);
	setup_client();
	sending_bits(pid, argv[2]);
	pause();
}