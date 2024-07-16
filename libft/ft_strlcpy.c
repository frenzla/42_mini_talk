/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:29:43 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 20:26:09 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < siz)
		ft_memcpy(dst, src, src_len + 1);
	else if (siz != 0)
	{
		ft_memcpy(dst, src, siz -1);
		dst[siz - 1] = 0;
	}
	return (src_len);
}
