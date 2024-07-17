/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:21 by alarose           #+#    #+#             */
/*   Updated: 2024/07/17 18:41:09 by alarose          ###   ########.fr       */
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

char	*check_args(int argc, char **argv, pid_t *pid)
{
	char *str;

	str = NULL;
	if (argc != 3)
		return (ft_printf(RED "Error: Wrong nb of args\n" RESET), NULL);
	if (ft_is_number(argv[1]) && kill(ft_atoi(argv[1]), 0) == 0)
	{
		*pid = ft_atoi(argv[1]);
		str = ft_strdup(argv[2]);
	}
	else if (ft_is_number(argv[2]) && kill(ft_atoi(argv[2]), 0) == 0)
	{
		*pid = ft_atoi(argv[2]);
		str = ft_strdup(argv[1]);
	}
	else
		return(ft_printf(RED "Error: wrong PID or process not active\n" RESET), NULL);
	if (!str)
		return(ft_printf(RED "Error: Give a msg to print\n" RESET), NULL);
	return (str);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
//	size_t	len;

	str = NULL;
	pid = -1;
	str = check_args(argc, argv, &pid);
	ft_printf("Valid PID: %d\n", pid);
	ft_printf("str      : %s\n", str);

	return (0);
}
