/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils_char.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 15:19:11 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 12:46:45 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fulfill_char(t_param p)
{
	int i;

	i = 0;
	while (i < p.flag[0])
	{
		if (p.flag[3])
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
}

size_t	ft_lf_fulfill_char(t_param p)
{
	size_t	len;

	len = 0;
	if (p.flag[0] >= 0)
	{
		len += p.flag[0];
		ft_fulfill_char(p);
	}
	return (len);
}

void	ft_display_char_start(t_param p)
{
	if (p.flag[4])
	{
		if (p.flag[1] && ft_strlen(p.s) && (ssize_t)ft_strlen(p.s) > p.flag[1])
			ft_putnstr(p.s, p.flag[1]);
		else if ((p.prec == 0 || !(ft_strlen(p.s))) ||
				(p.flag[1] > (ssize_t)ft_strlen(p.s)) ||
				p.negprec == 1)
			ft_putstr(p.s);
		else
			ft_putnstr(p.s, p.flag[1]);
	}
}

void	ft_display_char_end(t_param p)
{
	if (!p.flag[4])
	{
		if (p.flag[1] && ft_strlen(p.s) && (ssize_t)ft_strlen(p.s) > p.flag[1])
			ft_putnstr(p.s, p.flag[1]);
		else if ((p.prec == 0 || !(ft_strlen(p.s))) ||
				(p.flag[1] > (ssize_t)ft_strlen(p.s)) ||
				p.negprec == 1)
			ft_putstr(p.s);
		else
			ft_putnstr(p.s, p.flag[1]);
	}
}
