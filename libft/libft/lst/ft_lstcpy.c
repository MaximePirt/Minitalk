/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:36:53 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/30 03:54:34 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_datalstcpy(t_list *give, t_list **copy)
{

	*copy = NULL;
	while (give != NULL)
	{
		ft_lstadd_back(copy, ft_lstnew(give->payload));
		give = give->next;
	}
}