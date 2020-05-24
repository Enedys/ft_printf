# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kwillum <daniilxod@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 12:53:37 by Kwillum           #+#    #+#              #
#    Updated: 2020/05/21 15:09:51 by Kwillum          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBNAME		=	lftprintf
FLAGS		=	-Wall -Werror -Wextra
SRC_DIR		=	./src
LIBFT_DIR	=	./libft_src
OBJ_DIR		=	./objs

SRC			:=	ft_printf.c			process_aster_num.c		print_formated_str.c	list_formats_pcs.c	\
				list_formats_dxu.c	null_processing.c		ft_putstrn_fd.c			ft_itoa_ubase.c

LIBFT_SRC	:=	ft_bzero.c			ft_calloc.c				ft_itoa.c				ft_memset.c	\
				ft_putchar_fd.c 	ft_putstr_fd.c 			ft_strdup.c				ft_strlen.c	\
				ft_substr.c			ft_toupper.c 			ft_strjoin.c

HEADERS		:=	libftprintf.h			$(LIBFT_DIR)/libft.h

SRCS		:= 	$(addprefix $(SRC_DIR)/, $(SRC)) 			$(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC))

OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRC:c=o))		$(addprefix $(OBJ_DIR)/, $(LIBFT_SRC:c=o))

.PHONY: all, re, clean, fclean, tests, test_clean

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc  $@ $?
	@ranlib $@
	@echo "Done!"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: ./*/%.c $(HEADERS)| $(OBJ_DIR)
	@gcc $(FLAGS) -I. -c $< -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean 
	@/bin/rm -f $(NAME)

re: fclean all
