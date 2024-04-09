# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 12:26:58 by mpierrot          #+#    #+#              #
#    Updated: 2024/03/30 03:47:59 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR = includes
SRC_FILES = libft/mandatory/ft_atoi.c libft/mandatory/ft_bzero.c libft/mandatory/ft_calloc.c libft/mandatory/ft_isalnum.c \
			libft/mandatory/ft_isalpha.c libft/mandatory/ft_isascii.c libft/mandatory/ft_isdigit.c libft/mandatory/ft_isprint.c \
			libft/mandatory/ft_itoa.c libft/mandatory/ft_memchr.c libft/mandatory/ft_memcmp.c libft/mandatory/ft_memcpy.c \
			libft/mandatory/ft_memmove.c libft/mandatory/ft_memset.c libft/mandatory/ft_putchar_fd.c libft/mandatory/ft_putendl_fd.c \
			libft/mandatory/ft_putnbr_fd.c libft/mandatory/ft_putstr_fd.c libft/mandatory/ft_split.c libft/mandatory/ft_strchr.c \
			libft/mandatory/ft_strdup.c libft/mandatory/ft_striteri.c libft/mandatory/ft_strjoin.c libft/mandatory/ft_strlcat.c \
			libft/mandatory/ft_strlcpy.c libft/mandatory/ft_strlen.c libft/mandatory/ft_strmapi.c libft/mandatory/ft_strncmp.c \
			libft/mandatory/ft_strnstr.c libft/mandatory/ft_strrchr.c libft/mandatory/ft_strtrim.c libft/mandatory/ft_substr.c \
			libft/mandatory/ft_tolower.c libft/mandatory/ft_toupper.c \
			libft/lst/ft_lstadd_back.c libft/lst/ft_lstadd_front.c libft/lst/ft_lstclear.c \
			libft/lst/ft_lstcpy.c libft/lst/ft_lstdelone.c libft/lst/ft_lstiter.c libft/lst/ft_lstlast.c \
			libft/lst/ft_lstmap.c libft/lst/ft_lstnew.c libft/lst/ft_lstsize.c libft/lst/ft_pop_push.c libft/lst/ft_print_stack.c \
			libft/calculs/calcul_mediane.c \
			GNL/get_next_line.c GNL/get_next_line_utils.c \
			ft_printf/ft_printf.c ft_printf/ft_putptrfunc.c ft_printf/ft_usefulfonc.c \

SRCDIR = libft GNL ft_printf
OBJ_D = objs
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_D)/%.o)
CC = clang
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
AR = ar rcs
RM = rm -rf

DEFCOLOR = \033[0;39m
GREEN    = \033[1;92m
YELLOW   = \033[0;93m
PURPLE   = \033[0;95m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $@ $^
	@echo "$(GREEN)$(NAME) has been created successfully.$(DEFCOLOR)"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) $(OBJ_D)
	@echo "$(PURPLE)Object files have been removed.$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)$(NAME) has been removed.$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Libft was remake successfully $(DEFCOLOR)"

.PHONY: all clean fclean re