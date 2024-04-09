/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:43:12 by mpierrot          #+#    #+#             */
/*   Updated: 2024/03/12 12:15:24 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	c;

	if (!dst && !src)
		return (0);
	c = 0;
	if (src < dst)
	{
		c = len;
		while (c > 0)
		{
			c--;
			((unsigned char *)dst)[c] = ((unsigned char *)src)[c];
		}
	}
	else
	{
		while (c < len)
		{
			((unsigned char *)dst)[c] = ((unsigned char *)src)[c];
			c++;
		}
	}
	return (dst);
}
