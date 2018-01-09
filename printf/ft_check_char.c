/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:21:40 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/22 10:18:01 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_s(t_param p, va_list *ap, size_t len, char *fmt)
{
	int i;

	while (FLAG(*fmt) || FLAG2(*fmt))
		fmt++;
	p.str = va_arg(*ap, char*);
	len = ft_strlen(p.str);
	i = ft_atoisign(fmt) - len;
	if (p.flag[4])
		ft_putstr(p.str);
	if (i > 0)
	{
		len += i;
		while (i--)
			if (p.flag[3] && !(p.flag[4]))
				ft_putchar('0');
			else
				ft_putchar(' ');
	}
	if (!(p.flag[4]))
		ft_putstr(p.str);
	return (len);
}

size_t	ft_check_ws(t_param p, va_list *ap, size_t len)
{
	p.wstr = va_arg(*ap, wchar_t*);
	len = ft_strlen((char*)p.wstr);
	ft_putwstr(p.wstr);
	return (len);
}

size_t	ft_check_c(t_param p, va_list *ap, size_t len)
{
	p.c = va_arg(*ap, int);
	ft_putchar(p.c);
	len = 1;
	return (len);
}

size_t	ft_check_wc(t_param p, va_list *ap, size_t len)
{
	p.wc = va_arg(*ap, wchar_t);
	ft_putwchar(p.wc);
	len = 1;
	return (len);
}

size_t	ft_check_p(t_param p, va_list *ap, size_t len)
{
	p.ptr = va_arg(*ap, void*);
	ft_putstr("0x7fff");
	len = ft_get_len((int)p.ptr, 16) + 6;
	ft_print_base_low((int)p.ptr, 16);
	return (len);
}
