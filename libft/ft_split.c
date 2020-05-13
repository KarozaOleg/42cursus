/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:00:03 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/13 17:34:14 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_amount(const char *s, char c)
{
	int is_symbol;
	int amount;

	is_symbol = 1;
	amount = 0;
	while (*s)
	{
		if (*s == c)
			is_symbol = 1;
		else
		{
			if (is_symbol)
			{
				++amount;
				is_symbol = 0;
			}
		}
		++s;
	}
	return (amount);
}

char		**ft_split(const char *s, char c)
{
	char	**arr;
	int		i_arr;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	arr = malloc((return_amount(s, c) + 1) * sizeof(char*));
	if (arr == NULL)
		return (arr);
	i_arr = 0;
	i = 0;
	len = 0;
	while (1)
	{
		if (s[i] == c || s[i] == 0)
		{
			if (len > 0)
			{
				arr[i_arr++] = ft_substr(s, i - len, len);
				if (arr[i_arr - 1] == NULL)
				{
					while (--i_arr >= 0)
						free(arr[i_arr]);
					return (NULL);
				}
			}
			len = 0;
		}
		else
			++len;
		if (s[i++] == 0)
			break ;
	}
	arr[i_arr] = 0;
	return (arr);
}
