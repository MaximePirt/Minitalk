/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:39:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/05 22:32:53 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bitshifting(int sig, char *arg)
{
	size_t	i;
	char	a;
	int		scan;

	i = 0;
	printf("\n arg [%s]\n", arg);
	while (arg[i])
	{
		a = arg[i];
		scan = 1;
		scan <<= 14;
		while (scan != 0)
		{
			if (scan & a)
			{
				kill(sig, SIGUSR1);
				printf("sig1\n");
			}
			else
			{
				kill(sig, SIGUSR2);
				printf("sig2\n");
			}
			printf("Ca taff : [%d]\n", a);
			scan >>= 1;
			usleep(50);
		}
		printf("Changement de lettre !\n");
		i++;
	}
	a = '\0';
	scan = 1;
	scan <<= 14;
	while (scan != 0)
	{
		if (scan & a)
		{
			kill(sig, SIGUSR1);
			printf("sig1\n");
		}
		else
		{
			kill(sig, SIGUSR2);
			printf("sig2\n");
		}
		printf("Ca taff : [%d]\n", a);
		scan >>= 1;
		usleep(50);
	}
	printf("exit");
}

void	sig_handler(int sig)
{
	(void)sig;
	printf("\nSIG attrapé, on stop le programme %i\n", getpid());
}

int	main(int argc, char **argv)
{
	int AH;

	(void)argc;
	AH = ft_atoi(argv[1]);
	if (AH < 1 || argc < 2)
	{
		printf("NOOOOON");
		return (-1);
	}
	// sigaction(SIGUSR1);
	bitshifting(AH, argv[2]);
	return (1);
}