/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:02:31 by eplouzen          #+#    #+#             */
/*   Updated: 2024/04/23 01:00:23 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_put_i(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_put_c('-');
		n = -n;
		(*count)++;
	}
	if (n >= 10)
		ft_put_i(n / 10, count);
	ft_put_c(n % 10 + '0');
	(*count)++;
}

void	ft_put_uib(unsigned int nbr, char *base, int *count)
{
	unsigned int	count_base;

	count_base = 0;
	while (base[count_base])
		count_base++;
	if (nbr >= count_base)
	{
		ft_put_uib(nbr / count_base, base, count);
		ft_put_c(base[nbr % count_base]);
		(*count)++;
	}
	else
	{
		ft_put_c(base[nbr]);
		(*count)++;
	}
}

void	ft_put_ulb(unsigned long nbr, char *base, int *count)
{
	unsigned long	count_base;

	count_base = 0;
	if (!nbr)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	while (base[count_base])
		count_base++;
	if (nbr >= count_base)
	{
		ft_put_ulb(nbr / count_base, base, count);
		ft_put_c(base[nbr % count_base]);
		(*count)++;
	}
	else
	{
		ft_put_c(base[nbr]);
		(*count)++;
	}
}
