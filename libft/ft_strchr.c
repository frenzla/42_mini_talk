/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:40:34 by alarose           #+#    #+#             */
/*   Updated: 2024/05/01 17:19:49 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp_s;
	char	cc;

	tmp_s = (char *)s;
	cc = (char)c;
	while (*tmp_s)
	{
		if (*tmp_s == cc)
			return (tmp_s);
		tmp_s++;
	}
	if (*tmp_s == cc)
		return (tmp_s);
	return (NULL);
}
