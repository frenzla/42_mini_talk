/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:40:34 by alarose           #+#    #+#             */
/*   Updated: 2024/05/01 17:19:47 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	char	cc;

	tmp_s = NULL;
	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			tmp_s = (char *)s;
		s++;
	}
	if (*s == cc)
		tmp_s = (char *)s;
	return (tmp_s);
}
