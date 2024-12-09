/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrafai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 09:02:05 by yrafai            #+#    #+#             */
/*   Updated: 2024/12/01 09:02:07 by yrafai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	size_t	width;
	int		precision;
	int		plus;
	int		align;
	int		prefix;
	int		space;
	char	pad_char;
	char	conv;
}	t_format;

typedef struct s_vars
{
	size_t	size;
	size_t	precision;
	size_t	pad;
}	t_vars;

int				ft_printf(const char *format, ...);
int				is_valid_formatifier(char c);
int				is_valid_flag(char c);
void			write_char(char *character, int *out_len);
t_format		init_format(void);
const char		*set_specifications(const char *str, \
				t_format *format);
void			print_char(char character, t_format format, \
				int *out_len);
void			print_string(char *str, t_format format, \
				int *out_len);
void			print_hex(size_t number, \
				t_format format, int *out_len);
void			write_hex(size_t number, \
				char format, int *out_len);
void			write_number(long number, int *out_len);
void			print_int(long number, t_format format, \
				int *out_len);
int				count_decimal(long number);
int				count_hex(size_t number);
void			add_sign(long number, t_format format, \
				int *out_len);
void			put_repeat(char c, size_t count, int *out_len);

#endif
