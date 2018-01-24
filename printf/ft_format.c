/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 12:41:24 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 16:57:22 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_format(char *tmp, char *fmt, size_t *index)
{
	size_t	i;

	i = 0;
	while (!(FMT(tmp[i])) && !(FMT2(tmp[i])) && !(FMT3(tmp[i])) && tmp[i] != '%'
			&& tmp[i])
		i++;
	i += 1;
	fmt = ft_memalloc(i);
	ft_strncpy(fmt, tmp, i);
	*index = i;
	return (fmt);
}

void	ft_get_spec(t_param *p, const char *format, va_list *ap)
{
	ft_init_flag(p);
	ft_get_flag_first(p, format, ap);
	ft_get_flag_second(p, format);
}

int		ft_lf_star(const char *format, int index)
{
	while (!(FMT(format[index])) && !(FMT2(format[index]))
			&& !(FMT3(format[index])))
	{
		if (format[index] == '*' && format[index - 1] != '.')
			return (index);
		index++;
	}
	return (0);
}
