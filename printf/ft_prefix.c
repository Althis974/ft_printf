/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prefix.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 16:55:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:53:23 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_prefix(int base, int flaw, t_param *p)
{
	if (base == 16 && flaw == 0 && p->flag[2])
	{
		p->flag[2] = 0;
		if (p->unb == 0)
			return (0);
		ft_putstr("0x");
		return (2);
	}
	else if (base == 16 && flaw == 1 && p->flag[2])
	{
		p->flag[2] = 0;
		if (p->unb == 0)
			return (0);
		ft_putstr("0X");
		return (2);
	}
	else if (base == 8 && p->flag[2])
		return (ft_print_prefix_next(p));
	return (0);
}

size_t	ft_print_prefix_next(t_param *p)
{
	if (p->unb == 0 && p->flag[1] <= 0 && p->prec == 0)
	{
		p->flag[0] += 1;
		return (0);
	}
	ft_putchar('0');
	if (p->unb == 0 && p->flag[1] == 0 && p->flag[0] == 0 && p->prec == 1)
		return (1);
	else if (p->unb == 0 && p->flag[1] == 0 && p->flag[0] > 0 && p->prec == 1)
		return (0);
	p->flag[2] = 0;
	p->flag[1] -= 1;
	p->flag[0] += 1;
	return (1);
}

void	ft_print_base(t_param p, int base, int flow)
{
	if (flow == 0)
		ft_print_base_low(p.unb, base);
	else
		ft_print_base_upp(p.unb, base);
}

int		ft_regular_prefix(t_param *p, int base)
{
	int i;

	i = 0;
	if (p->flag[2] && !p->flag[4] && base == 16 && p->unb != 0)
		i += 2;
	else if (p->flag[2] && !p->flag[4] && base == 16 && p->unb == 0)
	{
		p->flag[0] -= 2;
		i = -2;
	}
	return (i);
}
