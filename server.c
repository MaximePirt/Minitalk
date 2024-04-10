/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:52:12 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 21:35:36 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static int		i = 0;
	static int		res = 0;
	static t_list	*lst = NULL;

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

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
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