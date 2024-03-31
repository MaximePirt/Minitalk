/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:39:58 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/31 07:21:17 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bitshifting(int sig, char *arg)
{
	size_t	i;
	int		a;
	int		c;

	c = 0;
	i = 0;
	printf("%s", arg);
	while (arg[i])
	{
		a = arg[i] - '0';
		while (c < 8)
		{
			c++;
			if ((a & 1) == 1)
				kill(sig, SIGUSR1);
			else if ((a & 1) == 0)
				kill(sig, SIGUSR2);
			else
				printf("soucis");
			a << 1;
			i++;
		}
	}
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