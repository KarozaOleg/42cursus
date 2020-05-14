/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:00:03 by mgaston           #+#    #+#             */
/*   Updated: 2020/05/14 14:02:54 by mgaston          ###   ########.fr       */
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

static int	is_error_substr(char **arr, int i_arr)
{
	if (arr[i_arr - 1] != NULL)
	{
		arr[i_arr] = 0;
		return (0);
	}
	while (--i_arr >= 0)
		free(arr[i_arr]);
	return (1);
}

static int	is_error_prelaunch(const char *s, char c, char ***p_arr)
{
	if (s == NULL)
		return (1);
	*p_arr = malloc((return_amount(s, c) + 1) * sizeof(char*));
	if (*p_arr == NULL)
		return (1);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		i_arr;
	int		i;
	int		len;

	if (is_error_prelaunch(s, c, &arr))
		return (NULL);
	i_arr = 0;
	i = 0;
	len = 0;
	while (i < 1 || s[i - 1] != 0)
	{
		if (s[i] == c || s[i] == 0)
		{
			if (len > 0)
				arr[i_arr++] = ft_substr(s, i - len, len);
			if (is_error_substr(arr, i_arr))
				return (NULL);
			len = 0;
		}
		else
			++len;
		++i;
	}
	return (arr);
}
