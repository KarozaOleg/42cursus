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

void print_answer_base(char *name, unsigned char *arr, size_t len)
{
    printf("%s: ", name);
    size_t i = 0;
    while(i < len)
    {
        printf("%c", arr[i]);
        ++i;
    }
    printf("\n");
}

void print_answer(unsigned char *arr, size_t len)
{
    print_answer_base("answer", arr, len);
}

void print_ft_answer(unsigned char *arr, size_t len)
{
    print_answer_base("ft_answer", arr, len);
}

void launcher(void (*f)(void))
{
    printf("--- start test: \"memset\"---\n"); 
    f();
    printf("--- end test: \"memset\"---\n\n");
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
    void *test(void *(*f)(void *dest, const void *src, int c, size_t n), void *src, int c, size_t len)
    {
        unsigned char *dest = malloc(len * sizeof(unsigned char));
        return f(dest, src, c, len);
    }
    size_t len = 5;
    unsigned char * src = malloc(len * sizeof(unsigned char));
    size_t i = 0;
    while(i < len)
    {
        src[i] = i + 48 + 1;
        ++i;
    }    

    unsigned char c = '2';

    unsigned char *answer = (unsigned char *)test(memccpy, src, c, len);
    print_answer(answer, len);

    unsigned char *ft_answer = (unsigned char *)test(ft_memccpy, src, c, len);
    print_ft_answer(ft_answer, len);

    free(answer);
    free(ft_answer);
    free(src);
}

int main()
{
    //launcher(test_memset);
    //launcher(test_bzero);
    launcher(test_memcpy);
    //launcher(test_memccpy);
    return 0;
}