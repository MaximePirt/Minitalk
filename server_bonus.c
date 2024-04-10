/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:52:12 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 21:59:18 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler_bonus(int sig, siginfo_t *info, void *context)
{
	static int		i = 0;
	static int		res = 0;
	static t_list	*lst = NULL;

	(void)context;
	i++;
	if (sig == 10)
		res |= 1;
	res <<= 1;
	if (!(i % 8))
	{
		res = ft_translate(res);
		ft_lstadd_back(&lst, ft_lstnew_int(res));
		if (res == 0)
		{
			print_stack(lst);
			ft_lstclear_c(&lst);
			usleep(50);
			kill(info->si_pid, SIGUSR1);
		}
		res = 0;
	}
}

int	ft_translate(int start)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i < 9)
	{
		res <<= 1;
		if (start & 1)
			res |= 1;
		start >>= 1;
		i++;
	}
	return (res);
}
void	setup(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler_bonus;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction", 2);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("sigaction", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	ft_printf("PID %d\n", getpid());
	setup();
	while (1)
		pause();
	return (1);
}