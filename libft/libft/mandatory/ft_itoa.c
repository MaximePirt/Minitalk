/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:15:51 by maxime_pier       #+#    #+#             */
/*   Updated: 2024/03/12 12:15:07 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	numlen(int n)
{
	size_t	b;

	b = 0;
	if (n == -2147483648)
		return (11);
	if (!n)
		return (1);
	if (n < 0)
	{
		b++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		b++;
	}
	return (b);
}

static char	*fillitoa(int n, size_t len, int negative, char *res)
{
	while (n > 0)
	{
		res[len-- + negative - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		negative;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = numlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	negative = (n < 0);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
		len--;
	}
	if (n == 0)
		res[0] = '0';
	res[len + negative] = '\0';
	fillitoa(n, len, negative, res);
	return (res);
}
