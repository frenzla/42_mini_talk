/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:21 by alarose           #+#    #+#             */
/*   Updated: 2024/07/26 14:51:47 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	next;

static int	*string_to_bin(size_t len, const char *str)
{
	int		*bin;
	size_t	i;
	int		j;
	size_t	index;
	char	c;

	bin = NULL;
	bin = malloc(sizeof(int) * len * 8);
	if (!bin)
		return (NULL);
	i = 0;
	index = 0;
	while (i < len)
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			bin[index] = (c >> j) & 1;
			j--;
			index++;
		}
		i++;
	}
	return (bin);
}

static int	ft_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (RET_ERR);
		i++;
	}
	if (i == 1 && arg[i - 1] == '0')
		return (RET_ERR);
	return (1);
}

static size_t	check_args(int argc, char **argv, pid_t *pid, char **str)
{
	if (argc != 3)
		return (ft_printf(RED "Error: Wrong nb of args\n" RESET), RET_ERR);
	if (ft_is_number(argv[1]) && kill(ft_atoi(argv[1]), 0) == 0)
	{
		*pid = ft_atoi(argv[1]);
		*str = ft_strdup(argv[2]);
	}
	else if (ft_is_number(argv[2]) && kill(ft_atoi(argv[2]), 0) == 0)
	{
		*pid = ft_atoi(argv[2]);
		*str = ft_strdup(argv[1]);
	}
	else
		return (ft_printf(RED \
		"Error: wrong PID or process not active\n" RESET), RET_ERR);
	if (!(*str))
		return (ft_printf(RED "Error: Input a msg to print\n" RESET), RET_ERR);
	return (ft_strlen(*str));
}

static void	return_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	next = 1;
	if (signum == SIGUSR2)
		ft_printf(BLUE "Msg received: %d bytes\n" RESET, i / 8);
	else if (signum == SIGUSR1)
		i++;
}

static int	handle_no_response(void)
{
	int k = 0;

	while (!next)
	{
		if (k == 50)
		{
			ft_printf(RED "No response from server\n" RESET);
			return (RET_ERR);
		}
		k++;
		usleep(100);
	}
	return (1);
}

static int	send_signals(int *bin, pid_t pid, size_t len)
{
	unsigned int	i;
	int				k;

	i = 0;
	while (i < (len * 8))
	{
		next = 0;
		if (bin[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		k = 0;
		if (!handle_no_response())
			return (RET_ERR);
	}
	return (1);
}

int	send_bits(int *bin, pid_t pid, size_t len)
{
	struct sigaction	sa;
	unsigned int		i;
	int					k;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &return_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting up signal handlers");
		return (RET_ERR);
	}
	if (!send_signals(bin, pid, len))
		return (RET_ERR);
	i = 0;
	while (i++ < 8)
	{
		next = 0;
		kill(pid, SIGUSR2);
		k = 0;
		handle_no_response();
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	size_t	len;
	int		*bin;

	str = NULL;
	pid = -1;
	len = check_args(argc, argv, &pid, &str);
	if (len == RET_ERR)
		return (1);
	bin = string_to_bin(len, str);
	if (!bin)
		return (ft_printf(RED "Error: couldn't transform to bin\n" RESET), 1);
	send_bits(bin, pid, len);
	free(str);
	free(bin);
	return (0);
}
