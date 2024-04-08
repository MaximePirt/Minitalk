/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/08 14:46:37 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <signal.h>

//////////////////
# include <stdio.h>
//////////////////
// void	sig_handler(int sig);
void	sig_handler(int sig, siginfo_t *info, void *context);
void	sig_handler_client(int sig, siginfo_t *info, void *context);

// server functions
int		traduc_shift(int sig, int res);
char	*strjoin_int(char *str, int int_char, int sig);

#endif