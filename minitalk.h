/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/09 14:43:41 by mpierrot         ###   ########.fr       */
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

void	ft_lstadd_back_kidecal(t_list **lst, t_list *new);
void	ft_lstclear_c(t_list **lst);

void	print_stack(t_list *stack);
t_list	*ft_lstnew_int(int content);

/* Server */
void	ft_received_char(int signum, siginfo_t *info, void *context);
void	ft_if(int *j, char *str);
/* client */
void	ft_send_char(int pid, int byte);
void	ft_send_str(int pid, char *str);
int		ft_check(char *stack);

#endif