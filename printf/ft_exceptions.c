/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_exceptions.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 10:24:00 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 13:55:18 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_zero_int(t_param p, size_t len, int base)
{
	if (p.flag[4])
		len += ft_zero_int_next(&p, base);
	if (p.flag[0])
	{
		p.flag[3] = 0;
		len += ft_lf_fulfill_nb(p, base);
	}
	if (!p.flag[4])
		len += ft_zero_int_next(&p, base);
	if (base == 10 && (p.flag[6] || p.flag[5]))
		len += 1;
	return (len);
}

size_t	ft_zero_int_next(t_param *p, int base)
{
	size_t i;

	i = 0;
	if (base == 8 && p->flag[2])
		i += ft_print_prefix(8, 0, p);
	if (base == 10 && p->flag[5] && p->utype == 0)
		ft_putchar('+');
	else if (base == 10 && p->flag[6] && p->utype == 0)
		ft_putchar(' ');
	return (i);
}

size_t	ft_lf_null(t_param p, size_t len)
{
	p.s = "(null)";
	len = 6;
	ft_display_char_start(p);
	if (!p.flag[1] && p.prec == 0)
		p.flag[0] -= len;
	else if (!(ft_strlen(p.s)))
		p.flag[0] -= len;
	else
		p.flag[0] -= p.flag[1];
	len += ft_lf_fulfill_char(p);
	ft_display_char_end(p);
	if (p.flag[1] < (ssize_t)ft_strlen(p.s) && p.prec == 1)
		len -= ft_strlen(p.s) - p.flag[1];
	return (len);
}

size_t	ft_zero_p(t_param p, size_t len, int base)
{
	if (p.flag[4])
		ft_zero_p_next(&p, &len);
	if (p.flag[3])
		ft_putstr("0x");
	if (p.flag[0])
	{
		if (p.flag[1])
			p.flag[0] -= 2 + p.flag[1];
		else if (p.flag[0] && p.prec == 1)
			p.flag[0] -= 2;
		else
			p.flag[0] -= 3;
		len += ft_lf_fulfill_nb(p, base);
	}
	if (!p.flag[4])
		ft_zero_p_next(&p, &len);
	len += 2;
	if (!p.flag[1] && p.prec == 0)
		len += 1;
	return (len);
}

void	ft_zero_p_next(t_param *p, size_t *len)
{
	if (p->flag[4])
		ft_putstr("0x");
	if (!p->flag[4] && !p->flag[3])
		ft_putstr("0x");
	ft_lf_fulfill_prec(p, len, 16, 0);
	if (!p->flag[1] && p->prec == 0)
		ft_putchar('0');
}
