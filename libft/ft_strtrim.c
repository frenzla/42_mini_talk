/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:09:28 by alarose           #+#    #+#             */
/*   Updated: 2024/05/02 11:42:43 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	end = 0;
	if (!s1)
		return (NULL);
	while (is_in_set(s1[i], set) && s1[i++])
		start++;
	if ((size_t)start == ft_strlen(s1))
		return (ft_substr(s1, start, 0));
	i = ft_strlen(s1) - 1;
	while (is_in_set(s1[i--], set))
		end++;
	str = ft_substr(s1, start, ft_strlen(s1) - start - end);
	return (str);
}
