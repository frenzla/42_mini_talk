/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:58:58 by alarose           #+#    #+#             */
/*   Updated: 2024/07/31 09:39:56 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (c == 0)
		{
			ft_printf(CYAN"\nEND OF MSG\n"RESET);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
	sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting up signal handlers");
		return (1);
	}
	pid = getpid();
	ft_printf("Process ID = \e[0;36m %d\n \x1b[0m", pid);
	while (1)
		pause();
	return (0);
}
