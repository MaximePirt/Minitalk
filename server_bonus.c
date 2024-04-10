/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:52:12 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 16:47:05 by mpierrot         ###   ########.fr       */
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
	// ft_printf("\n[%d]e appel de signal", i);
	// ft_printf("\n et voila le signal : [%d]", sig);
	if (sig == 10)
		res |= 1;
	res <<= 1;
	if (!(i % 8))
	{
		// ft_printf("\n\nVoila res avant ts [%d]\n", res);
		res = ft_translate(res);
		// ft_printf("\n\nVoila res apres ts [%d]\n", res);
		// ft_printf("\nVoila la valeur de i [%d]\n", i);
		ft_lstadd_back(&lst, ft_lstnew_int(res));
		if (res == 0)
		{
			// ft_putstr("\nres\n");
			print_stack(lst);
			ft_lstclear_c(&lst);
			usleep(500);
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
	// ft_printf("Voici l arrivee [%d]\n", start);
	while (i < 9)
	{
		res <<= 1;
		if (start & 1)
			res |= 1;
		start >>= 1;
		i++;
	}
	// ft_printf("Voici le resultat de res [%d]\n", res);
	return (res);
}
void	setup(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
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

int	main(void)
{
	printf("PID %d\n", getpid());
	setup();
	while (1)
		pause();
	return (1);
}