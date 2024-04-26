/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:02:39 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/23 18:21:11 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <signal.h>

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;
	static char	*str = NULL;
	char		str_c[2];

	(void)context;
	if (!str)
		str = ft_calloc(1, 1);
	if (sig == SIGUSR1)
		c += 1 << (i % 8);
	i++;
	if (!(i % 8))
	{
		str_c[0] = c;
		str_c[1] = '\0';
		str = ft_strjoinwhichfree(str, str_c);
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (1);
}
