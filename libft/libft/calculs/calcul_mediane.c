/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_mediane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:34:15 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/30 03:34:42 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	calcul_mediane(t_list *stack)
{
	size_t	res;

	res = ft_lstsize(stack);
	if (res % 2 == 0)
		res = res / 2;
	else
		res = (res + 1) / 2;
	return (res);
}
