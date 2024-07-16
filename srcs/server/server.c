/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:58:58 by alarose           #+#    #+#             */
/*   Updated: 2024/07/16 18:18:04 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Process ID = %d\n", pid);
	sleep(30);

	return (0);
}
