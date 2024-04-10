/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:51:59 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 16:46:05 by mpierrot         ###   ########.fr       */
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
			printf("\nVoici la valeur de 'a' [%d]", a);
			a >>= 1;
			c++;
			usleep(800);
		}
		i++;
	}
	c = 0;
	while (c < 8)
	{
		usleep(800);
		kill(pid, SIGUSR2);
		c++;
	}
}

void	sig_handler_client(int sig)
{
	(void)sig;
	printf("\nYour text has been print succesfully on the server");
}

void	setup_client(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler_client;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
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