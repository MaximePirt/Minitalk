/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefulfonc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:26 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/06 12:51:05 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)"), 6);
	i = 0;
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	char	*tmp;
	int		res;

	res = 0;
	tmp = ft_itoa(n);
	res += ft_putstr(tmp);
	free(tmp);
	return (res);
}

int	ft_unputnbr(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb > 9)
	{
		res += ft_unputnbr(nb / 10);
		res += ft_unputnbr(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
		return (ft_putchar(nb + '0'));
	return (res);
}

int	ft_puthexa(unsigned int nb, char *hexa)
{
	int	res;

	res = 0;
	if (nb >= 16)
	{
		res += ft_puthexa(nb / 16, hexa);
		res += ft_puthexa(nb % 16, hexa);
	}
	else
		res += ft_putchar(hexa[nb]);
	return (res);
}
