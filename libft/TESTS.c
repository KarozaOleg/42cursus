/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:30:32 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 14:30:32 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h";

void test_memset()
{
    void *test(void (*f)(void *s, int c, size_t n))
    {
        size_t len = 5;
        char *dest = malloc(len * sizeof(char));
        return f(dest, 'f', len);
    }    
    printf("--- start test: \"memset\"---");   

    unsigned char *answer = (unsigned char *)test(memset);
    printf("answer: %s\n", answer);

    unsigned char *ft_answer = (unsigned char *)test(ft_memset);
    printf("answer_ft: %s\n", ft_answer);

    printf("--- end test ---");
}

int main()
{
    test_memset();
    return 0;
}