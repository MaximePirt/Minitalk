/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:35:10 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/30 03:59:42 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pop(t_list **stack)
{
	int		value;
	t_list	*tmp;

	value = (*stack)->value;
	tmp = (*stack)->next;
	free(*stack);
	(*stack) = tmp;
	return (value);
}

int	ft_pop_end(t_list **stack)
{
	int		value;
	t_list	*tmp;
	t_list	*prev;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	value = tmp->value;
	if (!prev)
	{
		free(tmp);
		*stack = NULL;
	}
	else
	{
		prev->next = NULL;
		free(tmp);
	}
	return (value);
}
void	ft_push(t_list **stack, void *value)
{
	ft_lstadd_front(stack, ft_lstnew(value));
}
