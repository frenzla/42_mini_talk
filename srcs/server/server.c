/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:58:58 by alarose           #+#    #+#             */
/*   Updated: 2024/07/19 23:56:33 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	handler(int sig)
{
	static int	bit;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;
	struct sigaction sa;

	sa.sa_flags = 0;
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	pid = getpid();
	ft_printf("Process ID = %d\n", pid);
	while (1)
		pause();

	return (0);
}
