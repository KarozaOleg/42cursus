/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:00:03 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/05 15:00:03 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int return_amount(const char *s, char c)
{
	int isSymbol;
	int amount;

	isSymbol = 1;
	amount = 0;
	while(*s)
	{
		if(*s == c)
			isSymbol = 1;
		else
		{
			if(isSymbol)
			{
				++amount;
				isSymbol = 0;
			}
		}
		++s;
	}
	return (amount);
}

char **ft_split(const char *s, char c)
{
    char **arr;
	int iArr;
	int i;
	int len;
	
	if(s == NULL)
		return NULL;
	arr = malloc((return_amount(s, c) + 1) * sizeof(char*));
	if(arr == NULL)
		return (arr);
	iArr = 0;
	i = 0;
	len = 0;
	while(1)
	{
		if(s[i] == c || s[i] == 0)
		{
			if(len > 0)
			{
				arr[iArr++] = ft_substr(s, i - len, len);
				if(arr[iArr - 1] == NULL)
				{
					while(--iArr >= 0)
						free(arr[iArr]);
					return (NULL);
				}
			}
			len = 0;
		}
		else
			++len;
		if(s[i++] == 0)
			break;
	}	
	arr[iArr] = 0;
	return (arr);
}