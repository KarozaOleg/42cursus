/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:14:34 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/04 14:14:34 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
   size_t i;

  i = 0;
	while (dst[i] != '\0' && size > 0)
  {
	  --size;
	  ++i;      
  }
  return (i + ft_strlcpy(&dst[i], src, size));
}
/*
#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct answer
{
  size_t len;
  char *dest;
  int dest_size;
} tanswer;

tanswer test(int dest_size, char *src, size_t size, size_t (*f)(char *dst, const char *src, size_t size))
{
  char *dest = malloc(dest_size * sizeof(char));

  memset(dest, 0, dest_size);
  memset(dest, 'r', 6);
  dest[10] = 'a';

  tanswer answ;
  answ.len = f(dest, src, size);
  answ.dest = dest;
  answ.dest_size = dest_size;
  return answ;
}

void print_answer(tanswer answer, char *name)
{
  printf("%s dest:\n%.*s\n", name, answer.dest_size, answer.dest);
}

int main()
{
  int dest_size = 15;
  char *src = "lorem ipsum dolor sit amet";
  size_t size = 1;

  tanswer a1 = test(dest_size, src, size, strlcat);
  tanswer a2 = test(dest_size, src, size, ft_strlcat);

  print_answer(a1, "strlcat");
  print_answer(a2, "ft_strlcat");

  if(a1.len != a2.len)
    printf("answers not equal!\n");
  else
    printf("answers equal!\n");

  return 0;
}
*/
