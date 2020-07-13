/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 22:13:01 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/13 23:15:28 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"

int main()
{
	//"%5s", "goes over"
	// char *test ="123";
	// printf("0*,*d\n", 1);
	// schar *str = "hello, world!";

	// printf("answer1:%d\n", printf("%5%"));	
	// printf("\n");
	// printf("answer2:%d\n", ft_printf("%5%"));
	// %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c, %2c, %3c, %4c, %1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c";
	//':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',''";
	
	char *test_case = "%%";
	char *str = "tubular";

	int answer = printf(test_case);
	printf("\n");
	int answer2 = ft_printf(test_case);

	// if(answer != answer2)
	// 	printf("\n%d vs %d", answer, answer2);
		
	printf("\n");

	return 0;
}

//gcc main.c -lftprintf -L.
//gcc main.c -lftprintf -L. && ./a.out
//make re && gcc main.c -lftprintf -L. && ./a.out

//0*,*d
//min int
//max int
//min uint
//max uint