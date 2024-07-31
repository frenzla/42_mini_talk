# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alarose <alarose@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/16 16:33:54 by alarose           #+#    #+#              #
#    Updated: 2024/07/31 10:05:01 by alarose          ###   ########.fr        #
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

CLIENT_FILES = client.c \
				client_utils.c
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

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

all : $(SERVER) $(CLIENT)

./%.o : ./%.c
	@$(CC) $(CFLAGS) -g3 -ggdb3 $(INCLUDES) -o $@ -c $<

$(LIBFT_FILE) :
	@echo "$(YELLOW)Building libft...$(RESET)"
	@make --no-print-directory -C $(LIBFT_PATH)
	@echo "$(GREEN)Library $(LIBFT) successfully built...$(RESET)"

$(SERVER) : $(SERVER_OBJS) $(LIBFT_FILE)
	@$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)
	@echo "$(GREEN)Executable $(BLUE)'$@'$(GREEN) successfully built$(RESET)"

$(CLIENT) : $(CLIENT_OBJS) $(LIBFT_FILE)
	@$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)
	@echo "$(GREEN)Executable $(BLUE)'$@'$(GREEN) successfully built$(RESET)"

$(SERVER_BONUS) : $(SERVER_BONUS_OBJS) $(LIBFT_FILE)
	@$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)
	@echo "$(GREEN)Executable $(BLUE)'$@'$(GREEN) successfully built$(RESET)"

$(CLIENT_BONUS) : $(CLIENT_BONUS_OBJS) $(LIBFT_FILE)
	@$(CC) $(CFLAGS) -g3 -ggdb3 -o $@ $^ $(LIBFT_FLAGS)
	@echo "$(GREEN)Executable $(BLUE)'$@'$(GREEN) successfully built$(RESET)"

bonus : $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	@make --no-print-directory -C $(LIBFT_PATH) clean
	@$(RM) $(SERVER_OBJS)
	@$(RM) $(CLIENT_OBJS)
	@$(RM) $(TESTBINS)
	@$(RM) $(SERVER_BONUS_OBJS)
	@$(RM) $(CLIENT_BONUS_OBJS)
	@echo "$(RED)All '.o' files were removed$(RESET)"

fclean : clean
	@make --no-print-directory -C $(LIBFT_PATH) fclean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)
	@$(RM) $(SERVER_BONUS)
	@$(RM) $(CLIENT_BONUS)
	@echo "$(RED)Executable and library files were removed$(RESET)"

re : fclean all

re_bonus : fclean bonus

#re_test : fclean test

#$(TESTDIR)/%.o : $(TESTDIR)/%.c
#	$(CC) $(INCLUDES) $< $(OBJS) -g3 -ggdb3 -o $@ $(LIBFT_FLAGS) -I$(HOME)/Criterion/include/criterion -Wl,-rpath=$(HOME)/Criterion/build/src -L$(HOME)/Criterion/build/src -W -lcriterion

#test: $(OBJS) $(LIBFT_FILE) $(TESTBINS)
#	for test in $(TESTBINS) ; do ./$$test ; done

.PHONY: all clean fclean re re_test test bonus re_bonus
