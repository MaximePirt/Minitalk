/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:40:30 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/07 23:56:57 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	res = 0;
	static int	c = 0;
	static char	*str = NULL;

	// printf("Voila le suppose sig [%d]\n", info->si_pid);
	// printf("Ou lui [%d]\n", info->pid);
	(void)info;
	(void)context;
	c++;
	if (sig == 10)
		res += 1;
	if (c < 15)
		res <<= 1;
	if (c >= 15)
	{
		usleep(50);
		str = strjoin_int(str, res, sig);
		if (res == 0)
		{
			printf("\nvoila str : [%s]\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		c = 0;
		res = 0;
		printf("Sig sent");
	}
}

char	*strjoin_int(char *str, int int_char, int sig)
{
	char	*dst;
	size_t	i;

	(void)sig;
	// printf("\nCoucou jsuis le sig [%d]", sig);
	if (!str)
		dst = (char *)malloc(sizeof(char) * 2);
	else
		dst = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!dst)
	{
		printf("AH GROS C EST TROP");
		return (NULL);
	}
	i = 0;
	while (str && i < ft_strlen(str))
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = int_char;
	i++;
	dst[i] = '\0';
	if (str)
		free(str);
	return (dst);
}
void	setup(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
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
	(void)argc;
	(void)**argv;
	setup();
	printf("voila le pid %d\n", getpid());
	// printf("voila SIGUSR1 %d\n", SIGUSR1);
	// printf("voila SIGUSR2 %d\n", SIGUSR2);
	// sigaction(SIGUSR1, sig_handler, NULL);
	// sigaction(SIGUSR2, sig_handler, NULL);
	while (1)
		pause();
	return (1);
}
