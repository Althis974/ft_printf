/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u2ls_nb.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 14:01:04 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 17:16:38 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_start(t_param *p, size_t *len, int base, int flaw)
{
	if (p->flag[4])
	{
		if (base == 10)
		{
			if (p->flag[1])
			{
				ft_lf_fulfill_prec(p, len, 10, 0);
				ft_putnbr_nosign(p->nb);
			}
			else
			{
				if (p->flag[5])
					ft_putnbr_allsign(p->nb);
				else
					ft_putnbr(p->nb);
			}
		}
		else if (base == 16 || base == 8)
		{
			ft_lf_fulfill_prec(p, len, base, flaw);
			ft_print_base(*p, base, flaw);
		}
	}
}

void	ft_display_end(t_param *p)
{
	if (!p->flag[4])
	{
		if (p->flag[1] > 0)
			ft_putnbr_nosign(p->nb);
		else
		{
			if (p->flag[5] && !p->flag[3])
				ft_putnbr_allsign(p->nb);
			else if (p->flag[5] && p->flag[3] && p->flag[0] <= 0)
				ft_putnbr_allsign(p->nb);
			else if (p->flag[3] && p->flag[0] > 0)
				ft_putnbr_nosign(p->nb);
			else
				ft_putnbr(p->nb);
		}
	}
}

void	ft_display_base(t_param p, size_t *len, int base, int flaw)
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
	*len = i;
}
