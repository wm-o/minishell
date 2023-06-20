# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:30:30 by seojulee          #+#    #+#              #
#    Updated: 2023/04/20 16:24:58 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra #-Werror

SRCS		= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
			  ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strdup.c \
			  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			  ft_bzero.c  ft_toupper.c ft_tolower.c ft_atoi.c ft_calloc.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			@ ar -rcs $(NAME) $(OBJS)

$(OBJS)		: $(SRCS)
			@ $(CC) $(CFLAGS) -c $(SRCS) -I libft.h

clean		:
			@ rm -f $(OBJS)

fclean		: clean
			@ rm -f $(NAME)

re			: fclean all

.PHONY : all clean fclean re
