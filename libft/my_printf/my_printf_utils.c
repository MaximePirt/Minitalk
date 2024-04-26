/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:01:54 by eplouzen          #+#    #+#             */
/*   Updated: 2024/04/23 01:00:19 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_put_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_s(char *s)
{
	int	size;

	if (!s)
		return (write(1, "(null)", 6));
	size = ft_strlen(s);
	write(1, s, size);
	return (size);
}
