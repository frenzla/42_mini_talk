/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:15:03 by alarose           #+#    #+#             */
/*   Updated: 2024/04/29 19:48:44 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	cc;

	cc = (unsigned char)c;
	tmp_s = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*tmp_s == cc)
			return ((void *)tmp_s);
		tmp_s++;
	}
	return (NULL);
}
