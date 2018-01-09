/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_allsign.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/19 10:01:08 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/19 10:01:10 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_check_int_max(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
}

void			ft_putnbr_allsign(int n)
{
	int sign;

	sign = 0;
	ft_check_int_max(n);
	if (n < 0 && sign != 1)
		if (n != -2147483648)
		{
			ft_putchar('-');
			n *= -1;
			sign = 1;
		}
	if (n >= 0 && sign != 1)
	{
		ft_putchar('+');
		sign = 1;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}
