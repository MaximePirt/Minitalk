# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 04:05:11 by mpierrot          #+#    #+#              #
#    Updated: 2024/04/10 19:20:00 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_Client	= client.c
SRC_Server	= server.c mt_lst.c
Bonus_C = client_bonus.c
Bonus_S = server_bonus.c mt_lst.c

SRC_D	= srcs/
OBJ_D = objs

OBJ_FCLIENT = $(SRC_Client:%.c=$(OBJ_D)/%.o)
OBJ_FSERVER = $(SRC_Server:%.c=$(OBJ_D)/%.o)
Bonus_CF = $(Bonus_C:%.c=$(OBJ_D)/%.o)
Bonus_SF = $(Bonus_S:%.c=$(OBJ_D)/%.o)

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs
CLIENT = client
SERVER = server
Bonus_C_Exec = client_bonus
Bonus_S_Exec = server_bonus
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I includes/ -I $(LIBFT_DIR)/includes/

DEFCOLOR	= \033[0;39m
CYAN		= \033[1;96m
PURPLE		= \033[0;95m
YELLOW		= \033[0;93m
RED			= \033[0;91m




all: mandatory

mandatory:  $(CLIENT) $(SERVER)


$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(CLIENT): $(OBJ_FCLIENT) $(LIBFT)
	@$(CC) $(OBJ_FCLIENT) $(LIBFT) -o $(CLIENT) $(CFLAGS) $(INCLUDES)
	@echo "$(CYAN)Client has been compiled successfully$(DEFCOLOR)"

$(SERVER): $(OBJ_FSERVER) $(LIBFT)
	@$(CC) $(OBJ_FSERVER) $(LIBFT) -o $(SERVER) $(CFLAGS) $(INCLUDES)
	@echo "$(CYAN)Server has been compiled successfully$(DEFCOLOR)"

	
$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	@echo "$(YELLOW)Compiling $<$(DEFCOLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus:  $(Bonus_C_Exec) $(Bonus_S_Exec) 

$(Bonus_C_Exec): $(Bonus_CF) $(LIBFT)
	@$(CC) $(Bonus_CF) $(LIBFT) -o $(Bonus_C_Exec) $(CFLAGS) $(INCLUDES)
	@echo "$(CYAN)Client version bonus has been compiled successfully$(DEFCOLOR)"


$(Bonus_S_Exec): $(Bonus_SF) $(LIBFT)
	@$(CC) $(Bonus_SF) $(LIBFT) -o $(Bonus_S_Exec) $(CFLAGS) $(INCLUDES)
	@echo "$(CYAN)Server version bonus has been compiled successfully$(DEFCOLOR)"


clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(RM) objs 
	@echo "$(PURPLE)Minitalk object files cleaned !!$(DEFCOLOR)"

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(RM) $(CLIENT) $(SERVER) $(Bonus_C_Exec) $(Bonus_S_Exec)
	@echo "$(RED)Minitalk executable has been destroy$(DEFCOLOR)"

re: fclean all

.PHONY: all clean fclean re bonus

