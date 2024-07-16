/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:47:59 by alarose           #+#    #+#             */
/*   Updated: 2024/06/27 10:42:09 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct m_list
{
	char			c;
	struct m_list	*next;
}	t_gnl_list;

int		read_n_stock(int fd, char *buff, t_gnl_list **stock);
int		find_nl_or_eof(t_gnl_list **stock, int ret_read);
size_t	get_len(t_gnl_list **stock);
char	*cpy_n_free(t_gnl_list **stock, size_t nb_chars);
char	*get_next_line(int fd);
void	free_all(t_gnl_list **stock);

#endif
