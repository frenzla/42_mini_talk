/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:01:18 by alarose           #+#    #+#             */
/*   Updated: 2024/07/26 14:52:24 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "libft.h"
# include <stdio.h>

//ANSI color codes
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define CYAN "\e[0;36m"
# define BLUE "\e[0;34m"
# define RESET "\x1b[0m"

# define RET_ERR	0
# define TRUE		1
# define FALSE		0

#endif
