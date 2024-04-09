/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:40:30 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/09 15:18:30 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int		res = 0;
	static int		i = 0;
	static t_list	*end = NULL;
	static t_list	*start = NULL;

	(void)info;
	(void)context;
	// printf("ptet le soucis c est i [%d]\n", i);
	i++;
	if (sig == SIGUSR1)
		res |= 1;
	if (i < 9)
		res <<= 1;
	else
	{
		ft_lstadd_back_kidecal(&end, ft_lstnew_int(res));
		if (!start)
			start = end;
		if (res == 0)
		{
			print_stack(start);
			ft_lstclear_c(&start);
			end = NULL;
			start = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		res = 0;
	}
}

void	ft_lstclear_c(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		tmp->letter = 0;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	ft_lstadd_back_kidecal(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	if (*lst)
	{
		while ((*lst))
		{
			if ((*lst)->next == NULL)
				break ;
			(*lst) = (*lst)->next;
		}
		(*lst)->next = new;
		(*lst) = (*lst)->next;
	}
	else
		*lst = new;
}

t_list	*ft_lstnew_int(int content)
{
	t_list	*newNode;
	char	res;

	res = content;
	newNode = 0;
	newNode = malloc(sizeof(t_list) * 1);
	if (newNode == NULL)
		return (NULL);
	newNode->letter = res;
	newNode->next = NULL;
	return (newNode);
}

void	print_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		ft_printf("%c", tmp->letter);
		tmp = tmp->next;
	}
	ft_printf("%c\n", tmp->letter);
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
