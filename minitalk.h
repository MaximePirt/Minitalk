/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:07:32 by mpierrot          #+#    #+#             */
/*   Updated: 2024/04/05 22:17:46 by mpierrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/includes/libft.h"
# include <signal.h>

//////////////////
# include <stdio.h>
//////////////////
void	sig_handler(int sig);

// server functions
int		traduc_shift(int sig, int res);
char	*strjoin_int(char *str, int int_char);

#endif