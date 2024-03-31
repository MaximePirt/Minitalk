/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:40:30 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/31 07:22:12 by mpierrot         ###   ########.fr       */
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
	int	c;
	int	a;

	c = 0;
	a = 0;
	while (c < 8)
	{
	}
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
