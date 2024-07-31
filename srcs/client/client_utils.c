/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:49:21 by alarose           #+#    #+#             */
/*   Updated: 2024/07/31 09:41:24 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	g_next;

void	return_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	(void)info;
	g_next = 1;
	if (signum == SIGUSR2)
		ft_printf(CYAN "Msg received: %d bytes\n" RESET, i / 8);
	else if (signum == SIGUSR1)
		i++;
}

int	handle_no_response(void)
{
	int	k;

	k = 0;
	while (!g_next)
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

int	send_signals(int *bin, pid_t pid, size_t len)
{
	unsigned int	i;
	int				k;

	i = 0;
	while (i < (len * 8))
	{
		g_next = 0;
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

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &return_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
	sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting up signal handlers");
		return (RET_ERR);
	}
	if (!send_signals(bin, pid, len))
		return (RET_ERR);
	i = 0;
	while (i++ < 8)
	{
		g_next = 0;
		kill(pid, SIGUSR2);
		k = 0;
		handle_no_response();
	}
	return (1);
}
