/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/10 16:47:01 by mpierrot         ###   ########.fr       */
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

void	sig_handler_bonus(int sig, siginfo_t *info, void *context);
void	sending_bits(int pid, char *str);

// server bonus
void	sig_handler(int sig);

// server functions
int		traduc_shift(int sig, int res);
int		ft_translate(int start);

// Client functions
void	sig_handler_client(int sig);

// lst_func
void	ft_lstadd_back_kidecal(t_list **lst, t_list *new);
void	ft_lstclear_c(t_list **lst);
t_list	*ft_lstnew_int(int content);

// print func
void	print_stack(t_list *stack);

#endif