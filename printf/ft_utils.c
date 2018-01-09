/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 13:19:00 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 15:28:21 by rlossy      ###    #+. /#+    ###.fr     */
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

void	ft_lf_fulfill_prec(t_param *p, size_t *len, int base)
{
	size_t i;

	i = *len;
	if (p->flag[4])
	{
		if (p->flag[1])
		{
			p->flag[1] -= i;
			ft_fulfill_prec(*p, base);
			i += p->flag[1];
		}
		ft_lf_prefix(*p, base, 0);
	}
	if (p->flag[1] > 0 && !p->flag[4])
	{
		ft_fulfill_prec(*p, base);
		i += p->flag[1];
	}
	*len = i;
}
