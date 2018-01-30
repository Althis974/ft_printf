/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_int_2.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 13:40:38 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:17:00 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_b(t_param p, va_list *ap, size_t len)
{
	ft_cast_uint(&p, ap);
	if (p.unb == 0 && p.flag[1] == 0 && p.prec == 1)
		return (ft_zero_int(p, len, 2));
	ft_get_print_len(p.unb, 2, &len);
	ft_display_int_start(&p, &len, 2, 0);
	if (p.flag[1] && p.flag[1] >= (ssize_t)len)
		p.flag[0] -= p.flag[1];
	else
		p.flag[0] -= len;
	if (!p.flag[4])
		p.flag[1] -= len;
	len += ft_lf_fulfill_nb(p, 2);
	ft_display_int_base(p, &len, 2, 0);
	return (len);
}

size_t	ft_check_k(t_param p, va_list *ap, size_t len)
{
	t_date d;

	p.utype = 1;
	d.y = va_arg(*ap, int);
	d.m = va_arg(*ap, unsigned int);
	d.d = va_arg(*ap, unsigned int);
	if ((ft_valid_date(d) == (size_t)-1))
		return (-1);
	len = ft_get_len(d.y, 10) + ft_get_len(d.m, 10) + ft_get_len(d.d, 10);
	if (p.flag[4])
	{
		len += ft_display_date(d);
		p.flag[0] -= len;
	}
	if (!p.flag[4] && d.y >= 0)
		p.flag[0] -= len + 2;
	else if (!p.flag[4] && d.y < 0)
		p.flag[0] -= len + 6;
	len += ft_lf_fulfill_nb(p, 10);
	if (!p.flag[4])
		len += ft_display_date(d);
	return (len);
}

size_t	ft_valid_date(t_date d)
{
	if (d.d > 31 || d.m > 12)
		return (-1);
	else if ((d.m == 2 || d.m == 4 || d.m == 6 || d.m == 9 || d.m == 11)
			&& d.d > 30)
		return (-1);
	else if (d.m == 2 && d.d > 29)
		return (-1);
	else if (d.m == 2 && ((d.y % 4) != 0) && d.d == 29)
		return (-1);
	return (0);
}
