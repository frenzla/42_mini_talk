/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:13:28 by alarose           #+#    #+#             */
/*   Updated: 2024/05/23 20:16:53 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	cpy = NULL;
	len = ft_strlen(s);
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s, len + 1);
	return (cpy);
}
