/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 13:22:52 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:17:02 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list ap;
	size_t	len;

	len = 0;
	if (format)
	{
		va_start(ap, format);
		len = ft_lf_type(format, &ap);
		va_end(ap);
	}
	return (len);
}

size_t		ft_lf_type(const char *format, va_list *ap)
{
	t_format	f;
	t_param		p;

	f.len = 0;
	f.tmp = (char *)format;
	while (*f.tmp != '\0')
	{
		if (*f.tmp == '%')
		{
			f.fmt = ft_get_format(f.tmp, f.fmt, &f.index);
			ft_get_spec(&p, f.fmt, ap);
			if ((ft_lf_type_next(&f, p, ap)) == (size_t)-1)
				return (-1);
		}
		else if (*f.tmp != '\0')
		{
			ft_putchar(*f.tmp);
			f.len++;
			f.tmp++;
		}
	}
	return (f.len);
}

size_t		ft_lf_type_next(t_format *f, t_param p, va_list *ap)
{
	if ((f->lint = ft_get_t_int(f->fmt, ap, p)) == (size_t)-1)
	{
		ft_bzero((void*)f->fmt, f->index);
		ft_strdel(&f->fmt);
		return (-1);
	}
	if ((f->lchr = ft_get_t_char(f->fmt, ap, p)) == (size_t)-1)
	{
		ft_bzero((void*)f->fmt, f->index);
		ft_strdel(&f->fmt);
		return (-1);
	}
	f->len += f->lint + f->lchr;
	f->tmp += f->index;
	ft_bzero((void*)f->fmt, f->index);
	ft_strdel(&f->fmt);
	return (f->len);
}

size_t		ft_get_t_char(const char *format, va_list *ap, t_param p)
{
	size_t	len;

	len = 0;
	format++;
	while (*format)
	{
		if (*format == 's')
			return (ft_check_s(p, ap, len));
		else if (*format == 'c' || p.let != '\0')
			return (ft_check_c(p, ap, len));
		else if (*format == 'p')
			return (ft_check_p(p, ap, len));
		else if (*format == 'S')
			return (ft_check_ws(p, ap, len));
		else if (*format == 'C')
			return (ft_check_wc(p, ap, len));
		else if (*format == '%')
			return (ft_check_perc(p, len));
		if (ft_isalnocast(*format) == 1)
			break ;
		format++;
	}
	return (len);
}

size_t		ft_get_t_int(const char *format, va_list *ap, t_param p)
{
	size_t	len;

	len = 0;
	format++;
	while (*format)
	{
		if (*format == 'd' || *format == 'D' || *format == 'i')
			return (ft_check_d(p, ap, len));
		else if (*format == 'x')
			return (ft_check_x(p, ap, len));
		else if (*format == 'o' || *format == 'O')
			return (ft_check_o(p, ap, len));
		else if (*format == 'X')
			return (ft_check_wx(p, ap, len));
		else if (*format == 'u' || *format == 'U')
			return (ft_check_u(p, ap, len));
		else if (*format == 'b' || *format == 'B')
			return (ft_check_b(p, ap, len));
		else if (*format == 'k' || *format == 'K')
			return (ft_check_k(p, ap, len));
		if (ft_isalnocast(*format) == 1)
			break ;
		format++;
	}
	return (len);
}
