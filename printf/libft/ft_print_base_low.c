/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_base_low.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:11:40 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 15:59:24 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_base_low(unsigned int n, unsigned int base)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= base)
		ft_print_base_low(n / base, base);
	ft_putchar(hexa[n % base]);
}
