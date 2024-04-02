/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:40:30 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/02 02:00:25 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	(void)sig;
	printf("\nLesgo\n");
	////////////////////////////////////
}
void	traduc_shift(int sig, char a)
{
	int	i;
	int c;
	int	z;
	// char *tmp;
	

	i = 0;
	z = 0;
	(void)a;
		printf("OYO");

	(void)z;
	(void)sig;
	(void)i;
	while (i < 8)
	{
			c = c>>1;
		
		if (sig == SIGUSR1)
			c = c*10+1;
		else
			c = c*10;
		printf("OYO");
	}
	printf("Voila le res %d", c);
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	(void)**argv;
	i = 0;
	printf("voila le pid %d\n", getpid());
	// if (signal(SIGUSR1, sig_handler) < SIG_ERR)
	// 	exit(EXIT_FAILURE);
	signal(SIGUSR1, sig_handler);
	while (i != 1)
		pause();
	return (1);
}
