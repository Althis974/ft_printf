/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 13:31:12 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 15:27:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft/libft.h"

# define NB0(x) x >= '0' && x <= '9'
# define NB(x) x > '0' && x <= '9'
# define STR(x) ((x >= 32 && x <= 47) || (x >= 58 && x <= 126))

# define FMT(x) x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D'
# define FMT2(x) x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U'
# define FMT3(x) x == 'x' || x == 'X' || x == 'c' || x == 'C'

# define FLAG(x) x == 'h' || x == 'l' || x == 'j' || x == 'z' || x == '#'
# define FLAG2(x) x == '-' || x == '+' || x == ' ' || x == '0' || x == '%'

typedef struct			s_format
{
	char				*tmp;
	char				*start;
	char				*fmt;
	size_t				len;
}						t_format;

/*
**	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
**	|wid|pre| # | 0 | - | + |   | hh| h | ll|  l |  j |  z |
*/

typedef struct			s_param
{
	int					nb;
	long int			lnb;
	unsigned int		unb;
	unsigned long int	lunb;
	char				c;
	wchar_t				wc;
	char				*str;
	wchar_t				*wstr;
	void				*ptr;
	int					flag[13];
}						t_param;

/*
**	Functions that look for type
*/

int						ft_printf(const char *format, ...);
size_t					ft_lf_type(const char *format, va_list *ap);
char					*ft_get_format(char *tmp, char *fmt, size_t *index);
size_t					ft_get_type_char(const char *format, va_list *ap,
		char *tmp);
size_t					ft_get_type_int(const char *format, va_list *ap,
		char *tmp);

/*
**	Functions that look for flags
*/

void					ft_get_flag_first(t_param *p, const char *format,
		va_list *ap);
void					ft_get_flag_second(t_param *p, const char *format);
void					ft_init_flag(t_param *p);

/*
**	Functions that take care of width
*/

void					ft_fulfill_nb(t_param p, int base);
size_t					ft_lf_fulfill_nb(t_param p, int base);
void					ft_width_arg(t_param *p, int *val);
void					ft_get_width(t_param *p, const char *format, va_list *ap,
		int *index);

/*
**	Functions that take care of precision
*/

void					ft_fulfill_prec(t_param p, int base);
void					ft_get_prec(t_param *p, const char *format, va_list *ap,
		int *index);
void					ft_lf_fulfill_prec(t_param *p, size_t *len, int base);

/*
**	Functions that take care of prefix
*/

size_t					ft_print_prefix(int base, int flaw);
size_t					ft_lf_prefix(t_param p, int base, int flow);
int						ft_regular_index(t_param p, int base);

/*
**	Int-type Checkers
*/

size_t					ft_check_d(t_param p, va_list *ap, size_t len,
		char *fmt);
size_t					ft_check_x(t_param p, va_list *ap, size_t len,
		char *fmt);
size_t					ft_check_wx(t_param p, va_list *ap, size_t len,
		char *fmt);
size_t					ft_check_o(t_param p, va_list *ap, size_t len,
		char *fmt);
size_t					ft_check_u(t_param p, va_list *ap, size_t len);

/*
**	Char-type Checkers
*/

size_t					ft_check_s(t_param p, va_list *ap, size_t len,
		char *fmt);
size_t					ft_check_ws(t_param p, va_list *ap, size_t len);
size_t					ft_check_c(t_param p, va_list *ap, size_t len);
size_t					ft_check_wc(t_param p, va_list *ap, size_t len);
size_t					ft_check_p(t_param p, va_list *ap, size_t len);

#endif
