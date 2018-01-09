/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_base_upp.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 12:11:14 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/13 12:11:32 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_base_upp(unsigned int n, unsigned int base)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (n >= base)
		ft_print_base_upp(n / base, base);
	ft_putchar(hexa[n % base]);
}
