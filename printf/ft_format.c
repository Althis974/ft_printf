/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 12:41:24 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 13:00:15 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_format(char *tmp, char *fmt, size_t *index)
{
	size_t i;

	i = 0;
	while (!(FMT(tmp[i])) && !(FMT2(tmp[i])) && !(FMT3(tmp[i])) && tmp[i])
		i++;
	i += 1;
	fmt = ft_memalloc(i);
	ft_strncpy(fmt, tmp, i);
	*index = i;
	return (fmt);
}
