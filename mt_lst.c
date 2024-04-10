/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:30:44 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 15:47:36 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
