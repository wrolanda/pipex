# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrolanda <wrolanda@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 23:04:08 by wrolanda          #+#    #+#              #
#    Updated: 2022/01/25 17:04:49 by wrolanda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c\
			srcs/ft_flags_csdiu.c	srcs/ft_flags_pxX.c\
			libft/ft_putchar.c	libft/ft_putnbr.c	libft/ft_putstr.c\
			libft/ft_strlen.c srcs/ft_flags_sharp_bonus.c\

SRCS_B	=

HEADER	=	includes/ft_printf.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all so clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar	rcs	$(NAME) $?
# $? - The names of all prerequisites (separated by spaces) that are "newer" than the target

%.o	: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
# $<- The name of the first prerequisite.
# $@ - The file name of the target of the rule. If the target is an archive member, then '$ @' denotes the name of the archive file.

bonus	:	all

clean	:
	rm	-f $(OBJ) $(OBJ_B)

fclean	:	clean
	rm	-f $(NAME)

re	:	fclean all
