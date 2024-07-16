/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alarose <alarose@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:13:33 by alarose           #+#    #+#             */
/*   Updated: 2024/06/12 17:04:36 by alarose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define SET "cspdiuxX%"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		check_n_print(va_list args, char c, int *count);
int		p_hex(unsigned int nb, char x, int *count);
int		p_p(unsigned long nb, char x, int *count);
int		p_int(int n, int *count);
int		p_u(unsigned int u, int *count);
int		ft_putchar(int c, int *count);
int		ft_putstr(char *str, int *count);
char	is_in_set(char c);

#endif