/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 15:17:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 13:16:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_s(t_param p, va_list *ap, size_t len)
{
	if (p.flag[10])
		return (ft_check_ws(p, ap, len));
	p.s = va_arg(*ap, char*);
	if (!p.s)
		return (ft_lf_null(p, len));
	if (p.prec == 1 && p.flag[1] == 0)
		p.flag[3] = 0;
	len = ft_strlen(p.s);
	ft_display_char_start(p);
	if ((!p.flag[1] && p.prec == 0) || (!(ft_strlen(p.s))) ||
			(((ssize_t)ft_strlen(p.s)) < p.flag[1]))
		p.flag[0] -= len;
	else
		p.flag[0] -= p.flag[1];
	len += ft_lf_fulfill_char(p);
	ft_display_char_end(p);
	if (p.flag[1] < (ssize_t)ft_strlen(p.s) && p.prec == 1 && p.negprec == 0)
		len -= ft_strlen(p.s) - p.flag[1];
	return (len);
}

size_t	ft_check_ws(t_param p, va_list *ap, size_t len)
{
	p.ws = va_arg(*ap, wchar_t*);
	if (!p.ws)
		return (ft_lf_null(p, len));
	if (ft_valid_ws(p) == (size_t)-1)
		return (-1);
	len = ft_wstrlen(p.ws);
	ft_display_wchar_start(p);
	if ((!p.flag[1] && p.prec == 0) || (!(ft_wstrlen(p.ws))) ||
			(((ssize_t)ft_wstrlen(p.ws)) < p.flag[1]))
		p.flag[0] -= len;
	else if (p.flag[1] < (ssize_t)ft_wstrlen(p.ws) && p.prec == 1
			&& p.negprec == 0)
		p.flag[0] -= ft_wcharnput(p.ws, p.flag[1], 0);
	else
		p.flag[0] -= p.flag[1];
	len += ft_lf_fulfill_char(p);
	ft_display_wchar_end(p);
	if (p.flag[1] < (ssize_t)ft_wstrlen(p.ws) && p.prec == 1 && p.negprec == 0)
		len -= ft_wstrlen(p.ws) - ft_wcharnput(p.ws, p.flag[1], 0);
	return (len);
}

size_t	ft_check_c(t_param p, va_list *ap, size_t len)
{
	if (p.flag[10])
		return (ft_check_wc(p, ap, len));
	if (p.let != '\0')
		p.c = p.let;
	else
		p.c = va_arg(*ap, int);
	len = 1;
	if (p.flag[4])
		ft_putchar(p.c);
	p.flag[0] -= len;
	len += ft_lf_fulfill_char(p);
	if (!p.flag[4])
		ft_putchar(p.c);
	return (len);
}

size_t	ft_check_wc(t_param p, va_list *ap, size_t len)
{
	p.wc = va_arg(*ap, wint_t);
	if ((MB_CUR_MAX <= 1 && p.wc > 255) || (p.wc >= 0xd800 && p.wc <= 0xdfff)
			|| p.wc > 0x10FFFF || p.wc < 0)
		return (-1);
	if (MB_CUR_MAX == 1 && (p.wc >= 127) && (p.wc <= 255))
	{
		ft_putchar((char)p.wc);
		return (1);
	}
	len = ft_wcharlen(p.wc);
	if (p.flag[4])
		ft_putwchar(p.wc);
	p.flag[0] -= len;
	len += ft_lf_fulfill_char(p);
	if (!p.flag[4])
		ft_putwchar(p.wc);
	return (len);
}

size_t	ft_check_p(t_param p, va_list *ap, size_t len)
{
	p.ptr = va_arg(*ap, void*);
	p.flag[2] = 1;
	if ((p.unb = (uintmax_t)p.ptr) == 0)
		return (ft_zero_p(p, len, 16));
	ft_get_print_len(p.unb, 16, &len);
	ft_display_int_start(&p, &len, 16, 0);
	if (p.flag[1] && p.flag[1] >= (ssize_t)len)
		p.flag[0] -= p.flag[1];
	else
		p.flag[0] -= len;
	p.flag[0] -= ft_regular_prefix(&p, 16);
	if (p.flag[3] && p.flag[2] && !p.flag[4])
		len += ft_print_prefix(16, 0, &p);
	else if (p.flag[2] && !p.flag[4] && !p.flag[0])
	{
		len += ft_print_prefix(16, 0, &p);
		p.flag[1] += 2;
	}
	if (!p.flag[4])
		p.flag[1] -= len;
	len += ft_lf_fulfill_nb(p, 16);
	ft_display_int_base(p, &len, 16, 0);
	return (len);
}
