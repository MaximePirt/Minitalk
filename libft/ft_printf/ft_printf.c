/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:15:19 by mpierrot          #+#    #+#             */
/*   Updated: 2024/02/06 21:21:21 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

static int	ft_printf_sorter(char *c, va_list *args)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (*c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (*c == 'p')
		return (ft_putptr(va_arg(*args, void *)) + 2);
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (*c == 'u')
		return (ft_unputnbr(va_arg(*args, unsigned int)));
	else if (*c == 'x')
		return (ft_puthexa(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (*c == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (*c == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_printf_searcher(const char *format, va_list *args)
{
	int	res;

	res = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res += ft_printf_sorter((char *)format, args);
		}
		else
			res += ft_putchar(*format);
		format ++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	i += ft_printf_searcher((char *)format, &args);
	va_end(args);
	return (i);
}
