/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 09:53:08 by rlossy       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 16:14:03 by rlossy      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(int ac, char **av)
{
	// '-' argument a gauche, reste apres
	// '0' blank deviennent 0
	// int avant arg = nb espace avant
/*
	   int number = 9;
	   printf("%-10d\n", number);
	   printf("%010d\n", number);
	   printf("%-#10x\n", number);
	   printf("%#x\n", number);
*/
	/*
	   int conv = -128;
	   long conv2 = -128;
	   printf("d : %d \n", conv);
	   printf("D : %D \n", conv);
	   printf("ld : %ld \n", conv2);
	   printf("i : %i \n", conv);
	   printf("o : %o \n", conv);
	   printf("O : %O \n", conv);
	   printf("lo : %lo \n", conv2);
	   printf("x : %x \n", conv);
	   printf("X : %X \n", conv);
	   printf("u : %u \n", conv);
	   printf("U : %U \n", conv);
	   printf("lu : %lu \n", conv2);
	   */
	/*
	   double conv = 128;
	   printf("f : %f \n", conv);
	   printf("F : %F \n", conv);
	   printf("g : %g \n", conv);
	   printf("G : %G \n", conv);
	   printf("e : %e \n", conv);
	   printf("E : %E \n", conv);
	   */
	/*
	   '*' corresponding to width as argument
	   printf("hello %2$*1$d\n", -5, 10);
	   printf("hello %*d\n", -5, 10);
	   printf("%c\n", 'c');
	   printf("%C\n", 'C');
	   */

	if (!ac)
		return (1);
	printf("PRINTF :\n");
	//printf("\n%d\n", printf(av[1], av[2], atoi(av[3]), av[4], av[5][0], atoi(av[6]), av[7], atoi(av[8])));
	//printf("\n%d\n", printf("\n%C\n", L'猫'));
	//printf("\n%d\n", printf(av[1], av[2], av[3]));
	//printf("\n%d\n", printf(av[1], av[2]));
	//printf("\n%d\n", printf(av[1], atoi(av[2])));
	printf("\n%d\n", printf(av[1], atoi(av[2]), atoi(av[3])));
	//printf("\n%d\n", printf(av[1], atoi(av[2]), atoi(av[3]), atoi(av[4])));
	//printf("\n%d\n", printf(av[1], atoi(av[2]), av[3]));
	//printf("\n%d\n", printf(av[1], atoi(av[2]), av[3][0]));
	//printf("\n%d\n", printf(av[1], av[2][0]));
	printf("FT_PRINTF :\n");
	//printf("\n%d\n", ft_printf(av[1], av[2], atoi(av[3]), av[4], av[5][0], atoi(av[6]), av[7], atoi(av[8])));
	//printf("\n%d\n", ft_printf("\n%C\n", L'猫'));
	//printf("\n%d\n", ft_printf(av[1], av[2], av[3]));
	//printf("\n%d\n", ft_printf(av[1], av[2][0]));
	//printf("\n%d\n", ft_printf(av[1], av[2]));
	//printf("test : %C", L'猫');
	//printf("\n%d\n", ft_printf(av[1], atoi(av[2])));
	printf("\n%d\n", ft_printf(av[1], atoi(av[2]), atoi(av[3])));
	//printf("\n%d\n", ft_printf(av[1], atoi(av[2]), atoi(av[3]), atoi(av[4])));
	//printf("\n%d\n", ft_printf(av[1], atoi(av[2]), av[3]));
	//printf("\n%d\n", ft_printf(av[1], atoi(av[2]), av[3][0]));
	//printf("%S", L"我是一只猫。");
	//sSpdDioOuUxXcC

	return (0);
}
