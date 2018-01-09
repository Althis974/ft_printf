/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:21:40 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 15:30:20 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_check_d(t_param p, va_list *ap, size_t len, char *fmt)
{
	//printf("\nlen = %zu\n", len);
	//printf("\nwid = %d\n", p.flag[0]);
	//printf("\nprec = %d\n", p.flag[1]);
	p.nb = va_arg(*ap, int);
	if (p.flag[5])
		len = ft_get_len_sign(p.nb, 10);
	else
		len = ft_get_len(p.nb, 10);
	if (p.flag[6] && p.nb >= 0)
		ft_putchar(' ');
	if (p.flag[4])
	{
		if (p.flag[1])
		{
			if (p.flag[5] || p.nb < 0)
				p.flag[1] += 1;
			p.flag[1] -= len;
			ft_fulfill_prec(p, 10);
			len += p.flag[1];
			ft_putnbr_nosign(p.nb);
		}
		else
		{
			if (p.flag[5])
				ft_putnbr_allsign(p.nb);
			else
				ft_putnbr(p.nb);
		}
	}
	if (p.flag[0] && p.flag[1] && !p.flag[4] && !p.flag[5] && p.flag[1] > len)
		p.flag[0] -= p.flag[1];
	else if (p.flag[0] && p.flag[1] && !p.flag[4] && p.flag[5] && p.flag[1] > len)
		p.flag[0] -= p.flag[1] + 1;
	else if (p.flag[0] && p.flag[1] && !p.flag[4] && p.flag[5] && p.flag[1] == len)
		p.flag[0] -= len + 1;
	else
		p.flag[0] -= len;
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
	if (!p.flag[4])
	{
		if (p.flag[1] > 0)
			ft_putnbr_nosign(p.nb);
		else
		{
			if (p.flag[5] && !p.flag[3])
				ft_putnbr_allsign(p.nb);
			else if (p.flag[5] && p.flag[3] && p.flag[0] <= 0)
				ft_putnbr_allsign(p.nb);
			else if (p.flag[3] && p.flag[0] > 0)
				ft_putnbr_nosign(p.nb);
			else
				ft_putnbr(p.nb);
		}
	}
	return (len);
}

size_t	ft_check_x(t_param p, va_list *ap, size_t len, char *fmt)
{
	p.nb = va_arg(*ap, int);
	ft_get_print_len(p.nb, 16, &len);
	if (p.flag[4])
		ft_lf_fulfill_prec(&p, &len, 16);
	//if (p.flag[4])
	//{
	//	if (p.flag[1])
	//	{
	//		p.flag[1] -= len;
	//		ft_fulfill_prec(p, 16);
	//		len += p.flag[1];
	//	}
	//	len += ft_lf_prefix(p, 16, 0);
	//}
	if (p.flag[1] && p.flag[1] >= len)
		p.flag[0] -= p.flag[1];
	else
		p.flag[0] -= len;
	p.flag[0] -= ft_regular_index(p, 16);
	if (p.flag[3] && p.flag[2])
		len += ft_print_prefix(16, 0);
	if (!p.flag[4])
		p.flag[1] -= len;
	len += ft_lf_fulfill_nb(p, 16);
	//if (p.flag[1] > 0 && !p.flag[4])
	//{
	//	ft_fulfill_prec(p, 16);
	//	len += p.flag[1];
	//}
	if (!p.flag[4])
	{
		ft_lf_fulfill_prec(&p, &len, 16);
		len += ft_lf_prefix(p, 16, 0);
	}
	return (len);
}

size_t	ft_check_wx(t_param p, va_list *ap, size_t len, char *fmt)
{
	int	i;

	while (FLAG(*fmt) || FLAG2(*fmt))
		fmt++;
	if (p.flag[0])
		if ((i = va_arg(*ap, int)) < 0)
			ft_width_arg(&p, &i);
	p.nb = va_arg(*ap, int);
	ft_get_print_len(p.nb, 16, &len);
	if (p.flag[4])
		len += ft_lf_prefix(p, 16, 1);
	if (!p.flag[0])
		i = ft_atoisign(fmt) - len;
	else
		i -= len;
	i -= ft_regular_index(p, 16);
	if (p.flag[3] && p.flag[2])
		len += ft_print_prefix(16, 1);
	len += ft_lf_fulfill_nb(p, 16);
	if (!p.flag[4])
		len += ft_lf_prefix(p, 16, 1);
	return (len);
}

size_t	ft_check_o(t_param p, va_list *ap, size_t len, char *fmt)
{
	int i;

	while (FLAG(*fmt) || FLAG2(*fmt))
		fmt++;
	if (p.flag[0])
		if ((i = va_arg(*ap, int)) < 0)
			ft_width_arg(&p, &i);
	p.nb = va_arg(*ap, int);
	ft_get_print_len(p.nb, 8, &len);
	if (p.flag[4])
		len += ft_lf_prefix(p, 8, 0);
	if (!p.flag[0])
		i = ft_atoisign(fmt) - len;
	else
		i -= len;
	i -= ft_regular_index(p, 8);
	len += ft_lf_fulfill_nb(p, 8);
	if (!p.flag[4])
		len += ft_lf_prefix(p, 8, 0);
	return (len);
}

size_t	ft_check_u(t_param p, va_list *ap, size_t len)
{
	p.unb = va_arg(*ap, unsigned int);
	ft_putnbr(p.unb);
	len = ft_get_len(p.unb, 10);
	return (len);
}
