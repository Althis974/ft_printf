/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u2ls_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 12:24:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 13:56:07 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_wchar_start(t_param p)
{
	if (p.flag[4])
	{
		if (p.flag[1] && ft_wstrlen(p.ws) &&
				(ssize_t)ft_wstrlen(p.ws) > p.flag[1])
			ft_wcharnput(p.ws, p.flag[1], 1);
		else if ((p.prec == 0 || !(ft_wstrlen(p.ws))) ||
				(p.flag[1] > (ssize_t)ft_wstrlen(p.ws)) ||
				p.negprec == 1)
			ft_putwstr(p.ws);
		else
			ft_wcharnput(p.ws, p.flag[1], 1);
	}
}

void	ft_display_wchar_end(t_param p)
{
	if (!p.flag[4])
	{
		if (p.flag[1] && ft_wstrlen(p.ws) &&
				(ssize_t)ft_wstrlen(p.ws) > p.flag[1])
			ft_wcharnput(p.ws, p.flag[1], 1);
		else if ((p.prec == 0 || !(ft_wstrlen(p.ws))) ||
				(p.flag[1] > (ssize_t)ft_wstrlen(p.ws)) ||
				p.negprec == 1)
			ft_putwstr(p.ws);
		else
			ft_wcharnput(p.ws, p.flag[1], 1);
	}
}
