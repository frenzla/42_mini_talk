# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alarose <alarose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 16:33:54 by alarose           #+#    #+#              #
#    Updated: 2024/07/16 16:57:56 by alarose          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

SERVER_DIR = ./srcs/server/
SERVER_FILES = server.c
SERVER_SRCS = $(addprefix $(SERVER_DIR), $(SERVER_FILES))
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_DIR = ./srcs/client/
CLIENT_FILES = client.c
CLIENT_SRCS = $(addprefix $(CLIENT_DIR), $(CLIENT_FILES))
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

#BONUSDIR = ./bonuses/
#BONUS =		img_manager_bonus.c	\

LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FILE = $(LIBFT_PATH)$(LIBFT)
LIBFT_FLAGS = $(LIBFT_FILE) -L$(LIBFT_PATH) -lft

INCLUDES_PATH = ./includes
INCLUDES = -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

#BONUS_FILES = $(addprefix $(BONUSDIR), $(BONUS))
#OBJS_BONUS = $(BONUS_FILES:.c=.o)

TESTDIR =./tests
TESTS = $(wildcard $(TESTDIR)/*.c)
TESTBINS = $(TESTS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(SERVER) $(CLIENT)

./%.o : ./%.c
	$(CC) $(CFLAGS) -g3 -ggdb3 $(INCLUDES) -o $@ -c $<

$(LIBFT_FILE) :
	make -C $(LIBFT_PATH)

$(SERVER) : $(SERVER_OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)

$(CLIENT) : $(CLIENT_OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)

#.bonus : $(OBJS_BONUS) $(LIBFT_FILE)
#	$(CC) $(CFLAGS) -g3 -ggdb3 -o $(NAME) $^ $(LIBFT_FLAGS)
#	@touch $@

clean :
	make -C $(LIBFT_PATH) clean
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(TESTBINS)
	$(RM) $(OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re : fclean all

#re_bonus : fclean bonus

#re_test : fclean test

#$(TESTDIR)/%.o : $(TESTDIR)/%.c
#	$(CC) $(INCLUDES) $< $(OBJS) -g3 -ggdb3 -o $@ $(LIBFT_FLAGS) -I$(HOME)/Criterion/include/criterion -Wl,-rpath=$(HOME)/Criterion/build/src -L$(HOME)/Criterion/build/src -W -lcriterion

#test: $(OBJS) $(LIBFT_FILE) $(TESTBINS)
#	for test in $(TESTBINS) ; do ./$$test ; done

.PHONY: all clean fclean re re_test test bonus re_bonus
