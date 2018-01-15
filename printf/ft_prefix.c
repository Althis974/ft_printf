/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prefix.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 16:55:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 17:00:47 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_prefix(int base, int flaw, t_param *p)
{
	if (base == 16 && flaw == 0 && p->flag[2])
	{
		ft_putstr("0x");
		p->flag[2] = 0;
		return (2);
	}
	else if (base == 16 && flaw == 1 && p->flag[2])
	{
		ft_putstr("0X");
		p->flag[2] = 0;
		return (2);
	}
	else if (base == 8 && p->flag[2])
	{
		ft_putchar('0');
		p->flag[2] = 0;
		p->flag[1] -= 1;
		p->flag[0] += 1;
		return (1);
	}
	return (0);
}

void	ft_print_base(t_param p, int base, int flow)
{
	if (flow == 0)
		ft_print_base_low(p.nb, base);
	else
		ft_print_base_upp(p.nb, base);
}

int		ft_regular_prefix(t_param p, int base)
{
	int i;

	i = 0;
	if (p.flag[2] && !p.flag[4] && base == 8)
		i += 1;
	else if (p.flag[2] && !p.flag[4] && base == 16)
		i += 2;
	return (i);
}
