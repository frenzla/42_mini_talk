/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:24:11 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 20:13:31 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dst = (unsigned char *) dest;
	p_src = (unsigned char *) src;
	while (n-- > 0)
		*(p_dst++) = *(p_src++);
	return (dest);
}
