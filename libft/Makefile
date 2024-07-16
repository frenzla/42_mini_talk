# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alarose <alarose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 11:35:36 by alarose           #+#    #+#              #
#    Updated: 2024/06/12 16:46:22 by alarose          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR = ./
SRC = 	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c		\
		ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strnstr.c	\
		ft_atoi.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c		\
		ft_itoa.c		\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_printf.c				\
		ft_printf_utils.c		\
		get_next_line.c			\
		get_next_line_utils.c	\
		ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c		\

SRCS = $(addprefix $(SRCDIR), $(SRC))
HEADERS_PATH = ./
HEADERS = -I $(HEADERS_PATH)
CC = gcc
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
LIB = ranlib

all : ${NAME}

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	$(AR) $@ $^
	$(LIB) $@

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
