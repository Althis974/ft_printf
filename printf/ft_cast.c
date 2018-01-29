/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cast.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 13:17:40 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 16:56:02 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast_int(t_param *p, va_list *ap)
{
	if (p->flag[10] || p->ltype == 1)
		p->nb = (long int)va_arg(*ap, long int);
	else if (p->flag[11])
		p->nb = va_arg(*ap, intmax_t);
	else if (p->flag[9])
		p->nb = (long long int)va_arg(*ap, long long int);
	else if (p->flag[12])
		p->nb = (size_t)va_arg(*ap, size_t);
	else if (p->flag[8])
		p->nb = (short int)va_arg(*ap, int);
	else if (p->flag[7])
		p->nb = (char)va_arg(*ap, int);
	else
		p->nb = (int)va_arg(*ap, int);
}

void	ft_cast_uint(t_param *p, va_list *ap)
{
	if (p->flag[10] || p->ltype == 1)
		p->unb = (long unsigned int)va_arg(*ap, long unsigned int);
	else if (p->flag[11])
		p->unb = va_arg(*ap, uintmax_t);
	else if (p->flag[9])
		p->unb = (long long unsigned int)va_arg(*ap, long long unsigned int);
	else if (p->flag[12])
		p->unb = (size_t)va_arg(*ap, size_t);
	else if (p->flag[8])
		p->unb = (short unsigned int)va_arg(*ap, int);
	else if (p->flag[7])
		p->unb = (unsigned char)va_arg(*ap, int);
	else
		p->unb = (unsigned int)va_arg(*ap, unsigned int);
}
