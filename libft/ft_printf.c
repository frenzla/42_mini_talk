/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:15:51 by alarose           #+#    #+#             */
/*   Updated: 2024/05/30 09:48:43 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_hex(unsigned int nb, char x, int *count)
{
	if (nb >= 16)
		p_hex(nb / 16, x, count);
	if (x == 'x')
		ft_putchar(HEX_LOWER[nb % 16], count);
	else
		ft_putchar(HEX_UPPER[nb % 16], count);
	return (1);
}

int	p_p(unsigned long nb, char x, int *count)
{
	if (nb == 0)
	{
		ft_putstr("(nil)", count);
		return (1);
	}
	if (nb < 16)
		ft_putstr("0x", count);
	if (nb >= 16)
		p_p(nb / 16, x, count);
	if (x == 'x')
	{
		ft_putchar(HEX_LOWER[nb % 16], count);
		return (1);
	}
	else
	{
		ft_putchar(HEX_UPPER[nb % 16], count);
		return (1);
	}
	return (0);
}

int	p_int(int n, int *count)
{
	if (n == INT_MIN)
		return (ft_putstr("-2147483648", count), 1);
	if (n < 0)
	{
		ft_putchar('-', count);
		n = -n;
	}
	if (n >= 10)
		p_int(n / 10, count);
	ft_putchar(n % 10 + '0', count);
	return (1);
}

int	p_u(unsigned int u, int *count)
{
	if (u >= 10)
		p_u(u / 10, count);
	ft_putchar(u % 10 + '0', count);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	type;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	if (str == NULL)
		return (va_end(args), -1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		if (str[i] == '%' && is_in_set(str[i + 1]))
		{
			type = str[i + 1];
			check_n_print(args, type, &count);
			i += 2;
		}
		else
			ft_putchar(str[i++], &count);
	}
	va_end(args);
	return (count);
}
