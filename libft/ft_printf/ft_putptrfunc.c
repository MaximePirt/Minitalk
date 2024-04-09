/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptrfunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:31:28 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/06 12:52:45 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	i;
	int				res;

	i = (unsigned long) ptr;
	if (i == 0)
		return (ft_putstr("(nil)") - 2);
	else
	{
		ft_putstr("0x");
		return (ft_ptrhexa((unsigned long)i, "0123456789abcdef"));
	}
	return (res);
}

int	ft_ptrhexa(unsigned long nb, char *hexa)
{
	int	res;

	res = 0;
	if (nb >= 16)
	{
		res += ft_ptrhexa(nb / 16, hexa);
		res += ft_ptrhexa(nb % 16, hexa);
	}
	else
		res += ft_putchar(hexa[nb]);
	return (res);
}
