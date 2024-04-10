/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:51:59 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 22:24:02 by mpierrot         ###   ########.fr       */
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
			usleep(600);
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

int	main(int argc, char **argv)
{
	int pid = 0;
	if (argc < 2)
		return (-1);
	else
		pid = ft_atoi(argv[1]);
	if (pid < 1)
		return (-1);
	sending_bits(pid, argv[2]);
}