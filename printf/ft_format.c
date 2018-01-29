/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 12:41:24 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 16:47:06 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_format(char *tmp, char *fmt, size_t *index)
{
	size_t	i;

	i = 0;
	while (tmp[i] && !(ft_isalnocast(tmp[i])))
		i++;
	if (tmp[i] != '\0')
	{
		i += 1;
	}
	fmt = ft_memalloc(i);
	ft_strncpy(fmt, tmp, i);
	*index = i;
	return (fmt);
}

void	ft_get_spec(t_param *p, const char *format, va_list *ap)
{
	ft_init_flag(p);
	ft_get_invalid_conv(p, format);
	ft_get_flag_first(p, format, ap);
	ft_get_flag_second(p, format);
}

int		ft_lf_star(const char *format, int index)
{
	while (format[index])
	{
		if (ft_isalnocast(format[index]))
			break ;
		if (format[index] == '*' && format[index - 1] != '.')
			return (index);
		index++;
	}
	return (0);
}
