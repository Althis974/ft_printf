/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 13:31:12 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 12:46:09 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define NB0(x) x >= '0' && x <= '9'
# define NB(x) x > '0' && x <= '9'

# define FMT(x) x == 's' || x == 'S' || x == 'p' || x == 'c' || x == 'C'
# define FMT2(x) x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U'
# define FMT3(x) x == 'x' || x == 'X' || x == 'd' || x == 'D'

# define CAST(x) x == 'h' || x == 'l' || x == 'j' || x == 'z'

typedef struct			s_format
{
	char				*tmp;
	char				*fmt;
	size_t				len;
	size_t				index;
	size_t				lchr;
	size_t				lint;
}						t_format;

/*
**	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
**	|wid|pre| # | 0 | - | + |   | hh| h | ll|  l |  j |  z |
*/

typedef struct			s_param
{
	intmax_t			nb;
	uintmax_t			unb;
	char				c;
	wchar_t				wc;
	char				*s;
	wchar_t				*ws;
	void				*ptr;
	int					flag[13];
	int					prec;
	int					negprec;
	int					star;
	int					utype;
	int					ltype;
	int					let;
}						t_param;

/*
**	Functions that look for type
*/

int						ft_printf(const char *format, ...);
size_t					ft_lf_type(const char *format, va_list *ap);
size_t					ft_lf_type_next(t_format *f, t_param p, va_list *ap);
char					*ft_get_format(char *tmp, char *fmt, size_t *index);
size_t					ft_get_t_char(const char *format, va_list *ap,
		t_param p);
size_t					ft_get_t_int(const char *format, va_list *ap,
		t_param p);
void					ft_get_invalid_conv(t_param *p, const char *format);
/*
**	Functions that look for flags
*/
void					ft_get_spec(t_param *p, const char *format,
		va_list *ap);
void					ft_get_flag_first(t_param *p, const char *format,
		va_list *ap);
void					ft_get_flag_second(t_param *p, const char *format);
void					ft_init_flag(t_param *p);

/*
**	Functions that take care of width
*/

/*
** ---------------------------- NB --------------------------------
*/

void					ft_fulfill_nb(t_param p, int base);
size_t					ft_lf_fulfill_nb(t_param p, int base);
void					ft_width_arg(t_param *p, int *val);
void					ft_get_width(t_param *p, const char *format,
		va_list *ap, int *index);
int						ft_regular_wid(t_param p, size_t len);
int						ft_lf_star(const char *format, int index);

/*
** --------------------------- CHAR -------------------------------
*/

void					ft_fulfill_char(t_param p);
size_t					ft_lf_fulfill_char(t_param p);

/*
**	Functions that take care of precision
*/

void					ft_fulfill_prec(t_param p, int base);
void					ft_get_prec(t_param *p, const char *format, va_list *ap,
		int *index);
void					ft_lf_fulfill_prec(t_param *p, size_t *len, int base,
		int flow);
void					ft_lf_prec_next(t_param *p, size_t *len, int base);
size_t					ft_zero_int(t_param p, size_t len, int base);
size_t					ft_zero_int_next(t_param *p, int base);
size_t					ft_lf_null(t_param p, size_t len);
size_t					ft_get_wslen(t_param p, size_t len);
size_t					ft_valid_ws(t_param p);

/*
**	Functions that take care of prefix
*/

size_t					ft_print_prefix(int base, int flaw, t_param *p);
size_t					ft_print_prefix_next(t_param *p);
void					ft_print_base(t_param p, int base, int flaw);
int						ft_regular_prefix(t_param *p, int base);
size_t					ft_zero_p(t_param p, size_t len, int base);
void					ft_zero_p_next(t_param *p, size_t *len);

/*
**	Functions to print
*/

void					ft_display_int_start(t_param *p, size_t *len, int base,
		int flaw);
void					ft_display_int_end(t_param *p);
void					ft_display_int_base(t_param p, size_t *len, int base,
		int flaw);
void					ft_display_char_start(t_param p);
void					ft_display_char_end(t_param p);
void					ft_display_wchar_start(t_param p);
void					ft_display_wchar_end(t_param p);

/*
**	Functions that take care of cast
*/

void					ft_cast_int(t_param *p, va_list *ap);
void					ft_cast_uint(t_param *p, va_list *ap);

/*
**	Int-type Checkers
*/

size_t					ft_check_d(t_param p, va_list *ap, size_t len);
size_t					ft_check_x(t_param p, va_list *ap, size_t len);
size_t					ft_check_wx(t_param p, va_list *ap, size_t len);
size_t					ft_check_o(t_param p, va_list *ap, size_t len);
size_t					ft_check_u(t_param p, va_list *ap, size_t len);

/*
**	Char-type Checkers
*/

size_t					ft_check_s(t_param p, va_list *ap, size_t len);
size_t					ft_check_ws(t_param p, va_list *ap, size_t len);
size_t					ft_check_c(t_param p, va_list *ap, size_t len);
size_t					ft_check_wc(t_param p, va_list *ap, size_t len);
size_t					ft_check_p(t_param p, va_list *ap, size_t len);
size_t					ft_check_perc(t_param p, size_t len);

#endif
