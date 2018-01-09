/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_len_nosign.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 16:59:04 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 16:59:09 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_len_nosign(int val, int base)
{
	int len;

	len = 1;
	val = ft_abs(val);
	while (val /= base)
		len++;
	return (len);
}
