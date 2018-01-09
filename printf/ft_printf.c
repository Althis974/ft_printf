/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 13:22:52 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 10:23:25 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	size_t		i;
	t_format	f;

	f.len = 0;
	f.tmp = (char *)format;
	f.start = (char *)format;
	while (*f.tmp != '\0')
	{
		if (*f.tmp == '%')
		{
			f.fmt = ft_get_format(f.tmp, f.fmt, &i);
			ft_putnstr(f.start, f.tmp - f.start);
			f.len += ft_get_type_int(f.tmp, ap, f.fmt) +
				ft_get_type_char(f.tmp, ap, f.fmt);
			f.tmp += i;
			f.start = f.tmp;
		}
		else if (*f.tmp != '\0')
		{
			f.len++;
			f.tmp++;
		}
	}
	ft_putnstr(f.start, f.tmp - f.start);
	return (f.len);
}

size_t		ft_get_type_char(const char *format, va_list *ap, char *fmt)
{
	t_param	p;
	size_t	len;

	len = 0;
	ft_init_flag(&p);
	ft_get_flag_first(&p, format, ap);
	ft_get_flag_second(&p, format);
	while (*format++)
	{
		if (*format == 's')
			return (ft_check_s(p, ap, len, fmt));
		else if (*format == 'c')
			return (ft_check_c(p, ap, len));
		else if (*format == 'p')
			return (ft_check_p(p, ap, len));
		else if (*format == 'S')
			return (ft_check_ws(p, ap, len));
		else if (*format == 'C')
			return (ft_check_wc(p, ap, len));
		if ((FMT(*format)) || FMT2(*format) || (FMT3(*format)))
			break ;
	}
	return (len);
}

size_t		ft_get_type_int(const char *format, va_list *ap, char *fmt)
{
	t_param p;
	size_t	len;

	len = 0;
	ft_init_flag(&p);
	ft_get_flag_first(&p, format, ap);
	ft_get_flag_second(&p, format);
	while (*format++)
	{
		if (*format == 'd' || *format == 'D' || *format == 'i')
			return (ft_check_d(p, ap, len, fmt));
		else if (*format == 'x')
			return (ft_check_x(p, ap, len, fmt));
		else if (*format == 'o' || *format == 'O')
			return (ft_check_o(p, ap, len, fmt));
		else if (*format == 'X')
			return (ft_check_wx(p, ap, len, fmt));
		else if (*format == 'u' || *format == 'U')
			return (ft_check_u(p, ap, len));
		if ((FMT(*format)) || FMT2(*format) || (FMT3(*format)))
			break ;
	}
	return (len);
}
