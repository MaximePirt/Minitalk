/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:39:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/08 20:06:47 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bitshifting(int sig, char *arg)
{
	size_t	i;
	char	a;
	int		scan;

	i = 0;
	while (arg[i])
	{
		a = arg[i];
		scan = 1;
		scan <<= 8;
		while (scan != 0)
		{
			if (scan & a)
				kill(sig, SIGUSR1);
			else
				kill(sig, SIGUSR2);
			scan >>= 1;
			usleep(100);
		}
		i++;
		usleep(100);
		ft_putchar(a);
	}
	a = '\0';
	scan = 1;
	scan <<= 8;
	while (scan != 0)
	{
		if (scan & a)
			kill(sig, SIGUSR1);
		else
			kill(sig, SIGUSR2);
		scan >>= 1;
		usleep(100);
	}
	ft_putchar(a);
	ft_putchar('\n');
	printf("exit");
}

void	sig_handler_client(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	printf("\nLEsgo i got_it %i\n", getpid());
}

void	setup_client(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler_client;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
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
	int	sig;

	sig = 0;
	printf("Et voici mon PID [%i]\n", getpid());
	if (argc < 2)
	{
		printf("EHNOOOOON");
		return (-1);
	}
	printf("J ai %d arguments \n", argc);
	if (argc > 2)
		sig = ft_atoi(argv[1]);
	if (sig < 1)
	{
		printf("NOOOOON");
		return (-1);
	}
	setup_client();
	bitshifting(sig, argv[2]);
	return (1);
}
