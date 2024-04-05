/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:40:30 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/05 22:34:46 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static int	res = 0;
	static int	c = 0;
	static char	*str = NULL;

	(void)str;
	c++;
	if (sig == 10)
		res += 1;
	if (c < 15)
		res <<= 1;
	if (c >= 15)
	{
		str = strjoin_int(str, res);
		c = 0;
		printf("\nvoila res : [%s]\n", str);
	}
	// if (res == 0)
}

char	*strjoin_int(char *str, int int_char)
{
	char	*dst;
	size_t	i;

	if (!str)
		dst = (char *)malloc(sizeof(char) * 2);
	else
		dst = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (str && i < ft_strlen(str))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = int_char;
	i++;
	dst[i] = '\0';
	free(str);
	return (dst);
}

int	main(int argc, char **argv)
{
	int	i;

	(void)argc;
	(void)**argv;
	i = 0;
	printf("voila le pid %d\n", getpid());
	printf("voila SIGUSR1 %d\n", SIGUSR1);
	printf("voila SIGUSR2 %d\n", SIGUSR2);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (i != 1)
		pause();
	return (1);
}
