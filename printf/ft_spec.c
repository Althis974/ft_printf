/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_spec.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 10:02:15 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/09 15:26:15 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_get_width(t_param *p, const char *format, va_list *ap, int *index)
{
	int i;

	i = *index;
	if (format[i] == '*')
	{
		if ((p->flag[0] = va_arg(*ap, int)) < 0)
			ft_width_arg(p, &p->flag[0]);
	}
	else if (NB(format[i]))
	{
		p->flag[0] = ft_atoisign(format + i);
		while (NB0(format[i]))
			i++;
	}
	*index = i;
	//printf("\n index = %d, width = %d\n", i, p->flag[0]);
}

void	ft_get_prec(t_param *p, const char *format, va_list *ap, int *index)
{
	int i;

	i = *index;
	i++;
	if (format[i] == '*')
	{
		if ((p->flag[1] = va_arg(*ap, int)) < 0)
			p->flag[1] = 0;
	}
	else if (NB(format[i]))
	{
		p->flag[1] = ft_atoisign(format + i);
		while (NB0(format[i]))
			i++;
	}
	*index = i;
	//printf("\n index = %d, prec = %d\n", i, p->flag[1]);
}

void	ft_width_arg(t_param *p, int *val)
{
	int i;

	i = *val;
	p->flag[4] = 1;
	p->flag[3] = 0;
	i = ft_abs(i);
	*val = i;
}
