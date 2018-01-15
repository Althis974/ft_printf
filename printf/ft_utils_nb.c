/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 13:19:00 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 17:26:50 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fulfill_nb(t_param p, int base)
{
	int i;

	i = 0;
	if (p.flag[3] && base == 10)
	{
		if (p.nb >= 0 && p.flag[5])
			ft_putchar('+');
		else if (p.nb < 0)
			ft_putchar('-');
	}
	if (p.nb >= 0 && p.flag[6] && base == 10)
		i++;
	while (i < p.flag[0])
	{
		if (p.flag[3])
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
}

size_t	ft_lf_fulfill_nb(t_param p, int base)
{
	size_t	len;

	len = 0;
	if (p.flag[0] > 0)
	{
		len += p.flag[0];
		ft_fulfill_nb(p, base);
	}
	else if (p.flag[6] && p.flag[0] <= 0 && p.nb >= 0 && base == 10)
		len++;
	return (len);
}

void	ft_fulfill_prec(t_param p, int base)
{
	int i;

	i = 0;
	if (p.nb >= 0 && p.flag[5] && base == 10)
		ft_putchar('+');
	else if (p.nb < 0 && base == 10)
		ft_putchar('-');
	while (i < p.flag[1])
	{
		ft_putchar('0');
		i++;
	}
}

void	ft_lf_fulfill_prec(t_param *p, size_t *len, int base, int flaw)
{
	size_t i;

	i = *len;
	if (p->flag[4])
	{
		if (!p->flag[1] && p->flag[2] && (base == 16 || base == 8))
			i += ft_print_prefix(base, flaw, p);
		if (p->flag[1])
		{
			if ((p->flag[5] || p->nb < 0) && base == 10)
				p->flag[1] += 1;
			p->flag[1] -= i;
			if (p->flag[2] && (base == 16 || base == 8))
				i += ft_print_prefix(base, flaw, p);
			ft_fulfill_prec(*p, base);
			if (p->flag[1] > 0 || base == 10)
				i += p->flag[1];
		}
	}
	if (p->flag[1] > 0 && !p->flag[4])
	{
		ft_fulfill_prec(*p, base);
		if (p->flag[1] > 0 || base == 10)
			i += p->flag[1];
	}
	*len = i;
}

int		ft_regular_wid(t_param p, size_t len)
{
	int wid;

	wid = p.flag[0];
	if (p.flag[0] && p.flag[1] && !p.flag[4] && !p.flag[5]
			&& p.flag[1] > (ssize_t)len && p.nb > 0)
		wid -= p.flag[1];
	else if (p.flag[0] && p.flag[1] && !p.flag[4] && p.flag[1] > (ssize_t)len)
		wid -= p.flag[1] + 1;
	else if (p.flag[0] && p.flag[1] && !p.flag[4] && p.flag[1] == (ssize_t)len
			&& (p.flag[5] || (!p.flag[5] && p.nb < 0)))
		wid -= len + 1;
	else
		wid -= len;
	return (wid);
}
