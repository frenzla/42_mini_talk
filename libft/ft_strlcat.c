/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:51:18 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 20:25:11 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < siz && dst[i])
		i++;
	while ((i + j + 1) < siz && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != siz)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
