/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u2ls_nb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 14:01:04 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 15:53:59 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_int_start(t_param *p, size_t *len, int base, int flaw)
{
	if (p->flag[4])
	{
		if (base == 10 && p->utype == 0)
		{
			if (p->flag[1])
			{
				ft_lf_fulfill_prec(p, len, 10, 0);
				ft_putallnbr_nosign(p->nb);
			}
			else
			{
				if (p->flag[5])
					ft_putallnbr_allsign(p->nb);
				else
					ft_putallnbr(p->nb);
			}
		}
		else if (base == 16 || base == 8 || (base == 10 && p->utype == 1))
		{
			ft_lf_fulfill_prec(p, len, base, flaw);
			ft_print_base(*p, base, flaw);
		}
	}
}

void	ft_display_int_end(t_param *p)
{
	if (!p->flag[4])
	{
		if (p->flag[1] > 0)
			ft_putallnbr_nosign(p->nb);
		else
		{
			if (p->flag[5] && !p->flag[3])
				ft_putallnbr_allsign(p->nb);
			else if (p->flag[5] && p->flag[3] && p->flag[0] < 0)
				ft_putallnbr_allsign(p->nb);
			else if (p->flag[3] && p->flag[0] > 0)
				ft_putallnbr_nosign(p->nb);
			else
				ft_putallnbr(p->nb);
		}
	}
}

void	ft_display_int_base(t_param p, size_t *len, int base, int flaw)
{
	size_t i;

	i = *len;
	if (!p.flag[4] && base == 16)
	{
		if (p.flag[1] > 0 && p.flag[2])
			i += ft_print_prefix(16, flaw, &p);
		else if (p.flag[2] && p.flag[0] && !p.flag[3])
			i += ft_print_prefix(16, flaw, &p);
		ft_lf_fulfill_prec(&p, &i, 16, flaw);
		ft_print_base(p, 16, flaw);
	}
	else if (!p.flag[4] && base == 8)
	{
		if (p.flag[2] && !p.flag[4])
			i += ft_print_prefix(8, 0, &p);
		ft_lf_fulfill_prec(&p, &i, 8, 0);
		ft_print_base(p, 8, 0);
	}
	else if (!p.flag[4] && base == 10 && p.utype == 1)
	{
		ft_lf_fulfill_prec(&p, &i, 10, 0);
		ft_print_base(p, 10, 0);
	}
	*len = i;
}

int		ft_regular_wid(t_param p, size_t len)
{
	int	wid;

	wid = p.flag[0];
	if (p.flag[0] && p.flag[1] && !p.flag[4] && !p.flag[5]
			&& p.flag[1] > (ssize_t)len && p.nb >= 0)
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
