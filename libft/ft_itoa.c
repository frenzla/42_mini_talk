/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:36:13 by alarose           #+#    #+#             */
/*   Updated: 2024/05/01 10:49:41 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*alloc(int n, int nb_digits)
{
	char	*str;

	if (n < 0)
		str = malloc(sizeof(char) * (nb_digits + 2));
	else
		str = malloc(sizeof(char) * (nb_digits + 1));
	if (!str)
		return (NULL);
	str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		nb_digits;
	int		i;
	char	*str;
	long	nbr;

	nb_digits = get_nb_digits(n);
	str = alloc(n, nb_digits);
	nbr = n;
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		nbr *= -1;
	}
	str[i + nb_digits] = 0;
	while (nb_digits > 0)
	{
		str[i + nb_digits - 1] = nbr % 10 + '0';
		nbr /= 10;
		nb_digits--;
	}
	return (str);
}
