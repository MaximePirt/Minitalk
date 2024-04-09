/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:44:19 by maxime_pier       #+#    #+#             */
/*   Updated: 2024/03/12 13:07:07 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// external lib
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//main functions
int		ft_printf(const char *format, ...);

//useful functions
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_unputnbr(unsigned int nb);
int		ft_puthexa(unsigned int nb, char *hexa);
int		ft_ptrhexa(unsigned long nb, char *hexa);

//Libft part
char	*ft_itoa(int n);

#endif
