/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:21 by alarose           #+#    #+#             */
/*   Updated: 2024/07/26 15:51:40 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	send_bits(int *bin, pid_t pid, size_t len);

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
	{
		if (str)
			free(str);
		return (1);
	}
	bin = string_to_bin(len, str);
	if (!bin)
		return (ft_printf(RED "Error: couldn't transform to bin\n" RESET), 1);
	send_bits(bin, pid, len);
	free(str);
	free(bin);
	return (0);
}
