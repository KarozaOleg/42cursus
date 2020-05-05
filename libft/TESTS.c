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
#include <stdlib.h>
#include "libft.h"

void print_answer_base(char *name, unsigned char *str, size_t len)
{
    if(str == NULL)
    {
        printf("%s is NULL\n", name);
        return;
    }
    printf("%s: ", name);
    size_t i = 0;
    while(i < len)
    {
        printf("%c", str[i]);
        ++i;
    }
    printf("\n");
}

void print_answer(unsigned char *str, size_t len)
{
    print_answer_base("answer", str, len);
}

void print_ft_answer(unsigned char *str, size_t len)
{
    print_answer_base("ft_answer", str, len);
}

void test_memset()
{    
    void *test(void *(*f)(void *s, int c, size_t n))
    {
        size_t len = 5;
        char *dest = malloc(len * sizeof(char));
        return f(dest, 'f', len);
    }    
    unsigned char *answer = (unsigned char *)test(memset);
    printf("answer: %s\n", answer);
    free(answer);

    unsigned char *ft_answer = (unsigned char *)test(ft_memset);
    printf("ft_answer: %s\n", ft_answer);
    free(ft_answer);
}

/*
void test_bzero()
{
    void *test(void (*f)(void *s , size_t n), size_t len)
    {
        unsigned char *arr = malloc(len * sizeof(unsigned char));
        size_t i = 0;
        while(i < len)
        {
            arr[i] = i + 1;
            ++i;
        }
        f(arr, len);
        return arr;
    } 
    size_t len = 5;
    unsigned char * answer = (unsigned char *)test(bzero, len);
    print_answer(answer, len);

    unsigned char *ft_answer = (unsigned char *)test(ft_bzero, len);
    print_ft_answer(ft_answer, len);

    free(answer);
    free(ft_answer);
}
*/

void test_memcpy()
{
    void *test(void *(*f)(void *dest, const void *src, size_t n), const void *src, size_t len)
    {       
        unsigned char *dest = malloc(len * sizeof(unsigned char));
        return f(dest, src, len);
    }

    size_t len = 5;
    unsigned char *src = malloc(len * sizeof(unsigned char));
    size_t i = 0;
    while(i < len)
    {
        src[i] = i + 48 + 1;
        ++i;
    }

    unsigned char *answer = (unsigned char *)test(memcpy, src, len);
    printf("answer: %s\n", answer);

    unsigned char *ft_answer = (unsigned char *)test(ft_memcpy, src, len);
    printf("ft_answer: %s\n", ft_answer);

    free(answer);
    free(ft_answer);
    free(src);
}

void test_memccpy()
{
    typedef struct test_case
    {
        void *(*f)(void *dest, const void *src, int c, size_t n);
        char *src;
        int c;
        size_t len;
    } tcase;

    void *test(tcase tcase)
    {
        unsigned char *dest = malloc(tcase.len * sizeof(unsigned char));
        return tcase.f(dest, tcase.src, tcase.c, tcase.len);
    }      
    
    tcase tcase1;
    tcase1.f = ft_memccpy;
    tcase1.src = malloc(5 * sizeof(unsigned char));
    tcase1.c = '3';
    tcase1.len = len;    

    unsigned char *ft_answer = (unsigned char *)test(tcase1);
    print_ft_answer(ft_answer, len);
    free(ft_answer);
    
    /*
    unsigned char *answer = (unsigned char *)test(memccpy, src, c, len);
    print_answer(answer, len);
    free(answer);
    */
}

void launcher(void (*f)(void), char *name)
{
    printf("--- start test: \"%s\"---\n", name); 
    f();
    printf("--- end test: \"%s\"---\n\n", name);
}

int main()
{
    //launcher(test_memset);
    //launcher(test_bzero);
    //launcher(test_memcpy);
    //launcher(test_memccpy, "memccpy");

    char big[] = "Hello";
    char little[] = "llo";

    char *answer = strnstr(big, little, 10);
    printf("answer:%s", answer);
    return 0;
}