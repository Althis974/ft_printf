/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_prefix.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 16:55:20 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 14:42:55 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_prefix(int base, int flaw)
{
	if (base == 16 && flaw == 0)
	{
		ft_putstr("0x");
		return (2);
	}
	else if (base == 16 && flaw == 1)
	{
		ft_putstr("0X");
		return (2);
	}
	else if (base == 8)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}

size_t	ft_lf_prefix(t_param p, int base, int flow)
{
	int	len;

	len = 0;
	if (p.flag[2] && !p.flag[3])
		len += ft_print_prefix(base, flow);
	if (flow == 0)
		ft_print_base_low(p.nb, base);
	else
		ft_print_base_upp(p.nb, base);
	return (len);
}

int		ft_regular_index(t_param p, int base)
{
	int i;

	i = 0;
	if (p.flag[2] && !p.flag[4] && base == 8)
		i++;
	else if (p.flag[2] && !p.flag[4] && base == 16)
		i += 2;
	return (i);
}
