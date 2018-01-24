/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 15:12:38 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 15:42:18 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int main(void)
{
	setlocale(LC_ALL, "");
	//unsigned long int i = 4294967296;

	//printf("\nlen = %d\n", printf("test : %.i", 0));
	//printf("\nlen = %d\n", ft_printf("test : %.0i", 0));
//	printf("\nlen = %d\n", printf("test : %U", 4294967296));
//	printf("\nlen = %d\n", printf("test : %lx", 4294967296));
//	printf("\nlen = %d\n", ft_printf("test : %U", 4294967296));
//	printf("\nlen = %d\n", ft_printf("test : %lx", 4294967296));
	//printf("\nlen1 = %d\n", printf("test : %C", L"ሴ"));
	//printf("\nlen1 = %d\n\n", ft_printf("test : %C", L"ሴ"));
	//printf("\nlen2 = %d\n", printf("%C", L'猫'));
	//printf("\nlen2 = %d\n\n", ft_printf("%C", L'猫'));
	//printf("\nlen3 = %d\n",    printf("%C", L'ͳ'));
	//printf("\nlen3 = %d\n", ft_printf("%C", L'ͳ'));
	//printf("\nlen = %d\n", printf("test : %*.*s", 10, 4, "coucou"));
	//printf("\nlen = %d\n", ft_printf("test : %*.*s", 10, 4, "coucou"));
	//printf("\nlen = %d\n", printf("test : %.10p", 0));
	//printf("\nlen = %d\n", ft_printf("test : %.10p", 0));
/*
	printf("\n%s\n", "------PRINTF------");
	printf("\nlen = %d\n", printf("%S", L"中文!"));
	printf("\n%s\n", "------FT_PRINTF------");
	printf("\nlen = %d\n", ft_printf("%S", L"中文!"));
	printf("\n%s\n", "------PRINTF------");
	printf("\nlen = %d\n", printf("%S", L"猫猫"));
	printf("\n%s\n", "------FT_PRINTF------");
	printf("\nlen = %d\n", ft_printf("%S", L"猫猫"));
*/
	/*
	printf("\n%s\n", "------PRINTF------");
	printf("\nlen = %d\n", printf("%hC, %hC", 0, L'猫'));
	printf("\nlen = %d\n", ft_printf("%hC, %hC", 0, L'猫'));
	*/
//	printf("\n%s\n", "------PRINTF------");
	printf("\nlen = %d\n", printf("test : %10%"));
//	printf("\n%s\n", "------FT_PRINTF------");
	printf("\nlen = %d\n", ft_printf("test : %10%"));
}
