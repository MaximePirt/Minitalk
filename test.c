/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:29:03 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 14:16:31 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 16 % 8;
// 	if (!i)
// 		printf("ok");
// 	printf("voila i [%d]", i);
// 	return (0);
// }

// #include "minitalk.h"

// t_list	*ft_lstnew_int(int content)
// {
// 	t_list	*newNode;
// 	char	res;

// 	res = content;
// 	printf("in\n");
// 	// ft_printf("[%d], vla le content", content);
// 	newNode = 0;
// 	newNode = malloc(sizeof(t_list) * 1);
// 	if (newNode == NULL)
// 		return (NULL);
// 	printf("in2\n");
// 	newNode->letter = res;
// 	printf("\net une fois dans la stack[%c]\n", newNode->letter);
// 	newNode->next = NULL;
// 	printf("in3\n");
// 	return (newNode);
// }

// void	print_stack(t_list **stack)
// {
// 	t_list	*tmp;

// 	tmp = *stack;
// 	while (tmp->next)
// 	{
// 		ft_printf("[%c]\n", tmp->letter);
// 		tmp = tmp->next;
// 	}
// 	// ft_printf("[%c]\n", tmp->letter);
// }

// int	main(void)
// {
// 	t_list *lst;
// 	lst = NULL;

// 	lst = ft_lstnew_int(97);
// 	printf("[%c]\n", lst->letter);

// 	printf("[%c]\n", lst->letter);
// }