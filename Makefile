# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alarose <alarose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 16:33:54 by alarose           #+#    #+#              #
#    Updated: 2024/07/26 15:11:19 by alarose          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
CLIENT_BONUS = client_bonus
SERVER = server
SERVER_BONUS = server_bonus

SERVER_DIR = ./srcs/server/

SERVER_FILES = server.c
SERVER_SRCS = $(addprefix $(SERVER_DIR), $(SERVER_FILES))
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_DIR = ./srcs/client/

CLIENT_FILES = client.c
CLIENT_SRCS = $(addprefix $(CLIENT_DIR), $(CLIENT_FILES))
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

SERVER_BONUS_FILES = server_bonus.c
SERVER_BONUS_SRCS = $(addprefix $(SERVER_DIR), $(SERVER_BONUS_FILES))
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRCS:.c=.o)

CLIENT_BONUS_FILES =	client_bonus.c	\
						client_utils_bonus.c
CLIENT_BONUS_SRCS = $(addprefix $(CLIENT_DIR), $(CLIENT_BONUS_FILES))
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FILE = $(LIBFT_PATH)$(LIBFT)
LIBFT_FLAGS = $(LIBFT_FILE) -L$(LIBFT_PATH) -lft

INCLUDES_PATH = ./includes
INCLUDES = -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

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

$(SERVER_BONUS) : $(SERVER_BONUS_OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	make -C $(LIBFT_PATH) clean
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)
	$(RM) $(TESTBINS)
	$(RM) $(SERVER_BONUS_OBJS)
	$(RM) $(CLIENT_BONUS_OBJS)

fclean : clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	$(RM) $(SERVER_BONUS)
	$(RM) $(CLIENT_BONUS)

re : fclean all

re_bonus : fclean bonus

#re_test : fclean test

#$(TESTDIR)/%.o : $(TESTDIR)/%.c
#	$(CC) $(INCLUDES) $< $(OBJS) -g3 -ggdb3 -o $@ $(LIBFT_FLAGS) -I$(HOME)/Criterion/include/criterion -Wl,-rpath=$(HOME)/Criterion/build/src -L$(HOME)/Criterion/build/src -W -lcriterion

#test: $(OBJS) $(LIBFT_FILE) $(TESTBINS)
#	for test in $(TESTBINS) ; do ./$$test ; done

.PHONY: all clean fclean re re_test test bonus re_bonus
