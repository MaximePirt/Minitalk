/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:39:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 14:34:55 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	bitshifting(int sig, char *arg)
// {
// 	size_t	i;
// 	int		a;
// 	int		c;

// 	i = 0;
// 	printf("Voila le pid pour envoi [%d]\n", sig);
// 	while (arg[i])
// 	{
// 		a = arg[i];
// 		c = 8;
// 		while (c > 0)
// 		{
// 			usleep(1000);
// 			if (a & 1)
// 			{
// 				kill(sig, SIGUSR1);
// 				printf("Hop1\n");
// 			}
// 			else
// 			{
// 				kill(sig, SIGUSR2);
// 				printf("Hop2\n");
// 			}
// 			printf("\n Voici a [%d]", a);
// 			a >>= 1;
// 			// usleep(100);
// 			c--;
// 		}
// 		i++;
// 		usleep(600);
// 	}
// 	usleep(300);
// 	a = '\0';
// 	i = 8;
// 	while (i > 0)
// 	{
// 		usleep(400);
// 		kill(sig, SIGUSR2);
// 		i--;
// 	}
// 	ft_putchar(a);
// 	ft_putchar('\n');
// 	printf("exit");
// }

// void	sig_handler_client(int sig, siginfo_t *info, void *context)
// {
// 	(void)sig;
// 	(void)info;
// 	(void)context;
// 	printf("\nLEsgo i got_it %i\n", getpid());
// }

// void	setup_client(void)
// {
// 	struct sigaction	sa;

// 	sa.sa_sigaction = sig_handler_client;
// 	sa.sa_flags = SA_SIGINFO;
// 	sigemptyset(&sa.sa_mask);
// 	if (sigaction(SIGUSR1, &sa, NULL) == -1)
// 	{
// 		perror("sigaction");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (sigaction(SIGUSR2, &sa, NULL) == -1)
// 	{
// 		perror("sigaction");
// 		exit(EXIT_FAILURE);
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	sig;

// 	sig = 0;
// 	printf("Et voici mon PID [%i]\n", getpid());
// 	if (argc < 2)
// 		return (-1);
// 	if (argc > 2)
// 		sig = ft_atoi(argv[1]);
// 	if (sig < 1)
// 		return (-1);
// 	setup_client();
// 	bitshifting(sig, argv[2]);
// 	return (1);
// }
