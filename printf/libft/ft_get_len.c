/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_len.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 16:41:23 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 16:09:25 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_get_len(int val, int base)
{
	int len;

	len = 1;
	if (val < 0 && base == 10)
		len++;
	val = ft_abs(val);
	while (val /= base)
		len++;
	return (len);
}
