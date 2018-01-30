/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_int.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 15:18:53 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:17:06 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_d(t_param p, va_list *ap, size_t len)
{
	ft_cast_int(&p, ap);
	if (p.nb == 0 && p.flag[1] == 0 && p.prec == 1)
		return (ft_zero_int(p, len, 10));
	if (p.flag[5])
		len = ft_get_len_sign(p.nb, 10);
	else
		len = ft_get_len(p.nb, 10);
	if (p.flag[6] && p.nb >= 0)
		ft_putchar(' ');
	ft_display_int_start(&p, &len, 10, 0);
	p.flag[0] = ft_regular_wid(p, len);
	if (!p.flag[4])
		p.flag[1] -= len;
	len += ft_lf_fulfill_nb(p, 10);
	if (p.flag[1] >= 0 && !p.flag[4])
	{
		if (p.flag[5] || p.nb < 0)
			p.flag[1] += 1;
		ft_fulfill_prec(p, 10);
		if (p.flag[1] > 0)
			len += p.flag[1];
	}
	ft_display_int_end(&p);
	return (len);
}

size_t	ft_check_x(t_param p, va_list *ap, size_t len)
{
	ft_cast_uint(&p, ap);
	if (p.unb == 0 && p.flag[1] == 0 && p.prec == 1)
		return (ft_zero_int(p, len, 16));
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

size_t	ft_check_wx(t_param p, va_list *ap, size_t len)
{
	ft_cast_uint(&p, ap);
	if (p.unb == 0 && p.flag[1] == 0 && p.prec == 1)
		return (ft_zero_int(p, len, 16));
	ft_get_print_len(p.unb, 16, &len);
	ft_display_int_start(&p, &len, 16, 1);
	if (p.flag[1] && p.flag[1] >= (ssize_t)len)
		p.flag[0] -= p.flag[1];
	else
		p.flag[0] -= len;
	p.flag[0] -= ft_regular_prefix(&p, 16);
	if (p.flag[3] && p.flag[2] && !p.flag[4])
		len += ft_print_prefix(16, 1, &p);
	else if (p.flag[2] && !p.flag[4] && !p.flag[0])
	{
		len += ft_print_prefix(16, 1, &p);
		p.flag[1] += 2;
	}
	if (!p.flag[4])
		p.flag[1] -= len;
	len += ft_lf_fulfill_nb(p, 16);
	ft_display_int_base(p, &len, 16, 1);
	return (len);
}

size_t	ft_check_o(t_param p, va_list *ap, size_t len)
{
	ft_cast_uint(&p, ap);
	if (p.unb == 0 && (p.flag[1] == 0 || p.flag[1] == 1) && p.prec == 1)
		return (ft_zero_int(p, len, 8));
	ft_get_print_len(p.unb, 8, &len);
	if (p.flag[2] && p.flag[4] && p.flag[0] > 0)
		p.flag[0] -= 1;
	ft_display_int_start(&p, &len, 8, 0);
	if (p.flag[1] && p.flag[1] >= (ssize_t)len)
		p.flag[0] -= p.flag[1];
	else
		p.flag[0] -= len;
	if (!p.flag[4])
		p.flag[1] -= len;
	if (p.flag[2] && !p.flag[4] && p.flag[1] <= 0)
		p.flag[0] -= 1;
	len += ft_lf_fulfill_nb(p, 8);
	ft_display_int_base(p, &len, 8, 0);
	return (len);
}

size_t	ft_check_u(t_param p, va_list *ap, size_t len)
{
	p.utype = 1;
	ft_cast_uint(&p, ap);
	if (p.unb == 0 && p.flag[1] == 0 && p.prec == 1)
		return (ft_zero_int(p, len, 10));
	ft_get_print_len(p.unb, 10, &len);
	ft_display_int_start(&p, &len, 10, 0);
	if (p.flag[1] && p.flag[1] >= (ssize_t)len)
		p.flag[0] -= p.flag[1];
	else
		p.flag[0] -= len;
	if (!p.flag[4])
		p.flag[1] -= len;
	len += ft_lf_fulfill_nb(p, 10);
	ft_display_int_base(p, &len, 10, 0);
	return (len);
}
