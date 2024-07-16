/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:16:33 by alarose           #+#    #+#             */
/*   Updated: 2024/05/28 11:47:05 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_n_print(va_list args, char c, int *count)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int), count));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *), count));
	if (c == 'p')
		return (p_p(va_arg(args, unsigned long), 'x', count));
	if (c == 'd' || c == 'i')
		return (p_int(va_arg(args, int), count));
	if (c == 'u')
		return (p_u(va_arg(args, unsigned int), count));
	if (c == 'x')
		return (p_hex(va_arg(args, unsigned int), 'x', count));
	if (c == 'X')
		return (p_hex(va_arg(args, unsigned int), 'X', count));
	if (c == '%')
		return (ft_putchar('%', count));
	return (0);
}

int	ft_putchar(int c, int *count)
{
	char	cc;

	cc = (char)c;
	write(1, &cc, 1);
	(*count)++;
	return (1);
}

int	ft_putstr(char *str, int *count)
{
	if (!str)
		ft_putstr("(null)", count);
	else
		while (*str)
			ft_putchar(*str++, count);
	return (1);
}

char	is_in_set(char c)
{
	int	i;

	i = 0;
	while (SET[i])
	{
		if (c == SET[i])
			return (SET[i]);
		i++;
	}
	return (0);
}
