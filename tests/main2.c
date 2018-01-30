/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main2.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 15:12:38 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 15:52:40 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int main(void)
{
	//	setlocale(LC_ALL, "");
	//MB_CUR_MAX
	//if > 1 affiche unicode
	//sinon return -1
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
	//	printf("\nlen = %d\n", printf("test : %10%"));
	//	printf("\n%s\n", "------FT_PRINTF------");
	//	printf("\nlen = %d\n", ft_printf("test : %10%"));
	/*
	   printf("\n%s\n", "------PRINTF------");
	   printf("\nlen = %d\n", printf("%###-#0000 33...12..#0+0d", 256));
	   printf("\n%s\n", "------FT_PRINTF------");
	   printf("\nlen = %d\n", ft_printf("%###-#0000 33...12..#0+0d", 256));

	   printf("\n%s\n", "------PRINTF------");
	   printf("\nlen = %d\n", printf("%####0000 33..1..#00d\n", 256));
	   printf("\n%s\n", "------FT_PRINTF------");
	   printf("\nlen = %d\n", ft_printf("%####0000 33..1..#00d\n", 256));

	   printf("\n%s\n", "------PRINTF------");
	   printf("\nlen = %d\n", printf("{%05.*d}", -15, 42));
	   printf("\n%s\n", "------FT_PRINTF------");
	   printf("\nlen = %d\n", ft_printf("{%05.*d}", -15, 42));
	   *//*
			printf("\n%s\n", "------PRINTF------");
			printf("\nlen = %d\n", printf("%zhd", 4294967296));
			printf("\n%s\n", "------FT_PRINTF------");
			printf("\nlen = %d\n", ft_printf("%zhd", 4294967296));

			printf("\n%s\n", "------PRINTF------");
			printf("\nlen = %d\n", printf("%jhd", 9223372036854775807));
			printf("\n%s\n", "------FT_PRINTF------");
			printf("\nlen = %d\n", ft_printf("%jhd", 9223372036854775807));
			*/

	//	printf("\n%s\n", "------PRINTF------");
	//	printf("\nlen = %d\n", printf("{%.4S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	//	printf("\n%s\n", "------FT_PRINTF------");
	//	printf("\nlen = %d\n", ft_printf("{%.4S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));

	//	printf("\n%s\n", "------PRINTF------");
	//	printf("\nlen = %d\n", printf("%15.4S", L"我是一只猫。"));
	//	printf("\n%s\n", "------FT_PRINTF------");
	//	printf("\nlen = %d\n", ft_printf("%15.4S", L"我是一只猫。"));
	//	printf("\n%s\n", "------PRINTF------");
	//	printf("\nlen = %d\n", printf("{%.*s}", -1, "42"));
	//	printf("\n%s\n", "------FT_PRINTF------");
	//	printf("\nlen = %d\n", ft_printf("{%.*s}", -1, "42"));

	/*
	   printf("\nlen = %d\n", printf("%C", (wint_t)-2));
	   printf("\nlen = %d\n", ft_printf("%C", (wint_t)-2));
	   printf("\n-------------NEXT TEST------------------\n");

	   printf("\nlen = %d\n", printf("%C", 0xd800));
	   printf("\nlen = %d\n", ft_printf("%C", 0xd800));
	   printf("\n-------------NEXT TEST------------------\n");

	   printf("\nlen = %d\n", printf("%C", 0xdb02));
	   printf("\nlen = %d\n", ft_printf("%C", 0xdb02));
	   printf("\n-------------NEXT TEST------------------\n");

	   printf("\nlen = %d\n", printf("%C", 0xdfff));
	   printf("\nlen = %d\n", ft_printf("%C", 0xdfff));
	   printf("\n-------------NEXT TEST------------------\n");
	   */
	/*
	   printf("\nlen = %d\n", printf("%C", 0xbffe));
	   printf("\nlen = %d\n", ft_printf("%C", 0xbffe));
	   printf("\n-------------NEXT TEST------------------\n");

	   printf("\nlen = %d\n", printf("%lc", 254));
	   printf("\nlen = %d\n", ft_printf("%lc", 254));
	   printf("\n-------------NEXT TEST------------------\n");

	   printf("\nlen = %d\n", printf("%C", 256));
	   printf("\nlen = %d\n", ft_printf("%C", 256));
	   printf("\n-------------NEXT TEST------------------\n");
	   */
	//	printf("\nlen = %d\n", printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
	//	printf("\nlen = %d\n", ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
	//	printf("\n-------------NEXT TEST------------------\n");
	//	printf("\nlen = %d\n", printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
	//	printf("\nlen = %d\n", ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
	//	printf("\n-------------NEXT TEST------------------\n");
	//
	//	printf("\nlen = %d\n", printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));
	//	printf("\nlen = %d\n", ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a'));

	//	printf("\nlen = %d\n", printf("%C", 0xbffe));
	//	printf("\nlen = %d\n", ft_printf("%C", 0xbffe));

//		printf("\nlen = %d\n", printf("%+015f", 5.2));
//		printf("\nlen = %d\n", ft_printf("%+015f", 5.2));

//	wchar_t s[4];
//	setlocale(LC_ALL, "");
	//	s[0] = 0x53;
	//	s[1] = 0xd800;
	//	s[2] = 0x81000;
	//	s[3] = '\0';

//	s[0] = 0x53;
//	s[1] = 0x3abc;
//	s[2] = 0x81000;
//	s[3] = '\0';
//	printf("\nlen = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//	printf("\nlen = %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

//	printf("\nlen = %d\n", ft_printf("%.15b", 101));
//	printf("\nlen = %d\n", ft_printf("%.15b", 101));
//	printf("\nlen = %d\n", ft_printf("%b", 255));
//	printf("\nlen = %d\n", ft_printf("%B", 255));

	printf("\nlen = %d\n", ft_printf("%s%7s, tu fais parti du %d et tu dois etre niveau %d avant le %k, %s", "Bonjour", "Audric", 101, 5, 2018, 3, 8, "MAGNE TOI !"));
//	printf("\nlen = %d\n", ft_printf("%0-15K", -10, 5, 31));
}
