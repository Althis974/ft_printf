/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 10:09:18 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 13:16:05 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_flag_first(t_param *p, const char *format, va_list *ap)
{
	int i;

	i = 0;
	while (format[++i])
	{
		if (((format[i] == '*' || (NB(format[i]))) && format[i - 1] != '.'))
			ft_get_width(p, format, ap, &i);
		if (format[i] == '.')
			ft_get_prec(p, format, ap, &i);
		if (format[i] == '#')
			p->flag[2] = 1;
		if (format[i] == '0' && !(NB0(format[i - 1])) && format[i - 1] != '.')
			p->flag[3] = 1;
		if (format[i] == '-')
			p->flag[4] = 1;
		if (format[i] == '+')
			p->flag[5] = 1;
		if (format[i] == ' ')
			p->flag[6] = 1;
		if (ft_isalnocast(format[i]))
			break ;
	}
	if (((p->flag[1] || (p->prec && !p->negprec)) && (FMT2(format[i]) ||
		FMT3(format[i]))) || p->flag[4])
		p->flag[3] = 0;
}

void	ft_get_flag_second(t_param *p, const char *format)
{
	int i;

	i = 0;
	while (format[++i] && !ft_isalnocast(format[i]))
	{
		if (format[i] == 'h' && format[i - 1] != 'h')
			if ((format[i + 1]) == 'h')
				p->flag[7] = 1;
			else
				p->flag[8] = 1;
		else if (format[i] == 'l' && format[i - 1] != 'l')
			if ((format[i + 1]) == 'l')
				p->flag[9] = 1;
			else
				p->flag[10] = 1;
		else if (format[i] == 'j')
			p->flag[11] = 1;
		else if (format[i] == 'z')
			p->flag[12] = 1;
	}
	if (format[i] == 'D' || format[i] == 'U' || format[i] == 'O')
		p->ltype = 1;
	if (p->flag[5])
		p->flag[6] = 0;
}

void	ft_get_invalid_conv(t_param *p, const char *format)
{
	int	i;

	i = 1;
	while (format[i])
	{
		if (FMT(format[i]) || FMT2(format[i]) || FMT3(format[i])
				|| format[i] == '%')
			return ;
		if (ft_isvalid_conv(format[i]) == 0 && !(NB0(format[i]))
				&& !(CAST(format[i])))
		{
			p->let = format[i];
			return ;
		}
		i++;
	}
}

void	ft_init_flag(t_param *p)
{
	p->flag[0] = 0;
	p->flag[1] = 0;
	p->flag[2] = 0;
	p->flag[3] = 0;
	p->flag[4] = 0;
	p->flag[5] = 0;
	p->flag[6] = 0;
	p->flag[7] = 0;
	p->flag[8] = 0;
	p->flag[9] = 0;
	p->flag[10] = 0;
	p->flag[11] = 0;
	p->flag[12] = 0;
	p->star = 0;
	p->prec = 0;
	p->negprec = 0;
	p->utype = 0;
	p->ltype = 0;
	p->let = '\0';
}
