/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:21 by alarose           #+#    #+#             */
/*   Updated: 2024/07/16 21:47:21 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int ft_is_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (RET_ERR);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv, pid_t *pid, char *str)
{
	(void) str; // to check str
	if (argc != 3)
		return (ft_printf(RED "Error: Wrong nb of args\n" RESET), RET_ERR);
	if (ft_is_number(argv[1]) && kill(ft_atoi(argv[1]), 0) == 0)
		*pid = ft_atoi(argv[1]);
	else if (ft_is_number(argv[2]) && kill(ft_atoi(argv[2]), 0) == 0)
		*pid = ft_atoi(argv[2]);
	else
		return(ft_printf(RED "Error: wrong PID or process not active\n" RESET), RET_ERR);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	str = NULL;
	pid = -1;
	if (!check_args(argc, argv, &pid, str))
		return (1);
	ft_printf("Valid PID: %d\n", pid);
	return (0);
}
