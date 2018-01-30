/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u2ls_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 12:24:27 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 17:25:53 by rlossy      ###    #+. /#+    ###.fr     */
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

size_t	ft_valid_ws(t_param p)
{
	int		i;
	int		pos;
	size_t	ret;

	i = 0;
	while (p.ws[i])
	{
		if ((MB_CUR_MAX <= 1 && p.ws[i] > 255) ||
				(p.ws[i] >= 0xd800 && p.ws[i] <= 0xdfff)
				|| p.ws[i] > 0x10FFFF || p.ws[i] < 0)
		{
			ret = -1;
			pos = i;
			break ;
		}
		i++;
	}
	if (p.flag[1])
	{
		if (ret == (size_t)-1 && p.flag[1] > pos)
			return (-1);
	}
	else if (ret == (size_t)-1)
		return (-1);
	return (0);
}
