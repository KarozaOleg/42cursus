/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:07:51 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/05 14:16:23 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	mem_copy_ds(char *dest, char *src, int dest_shift, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dest[i + dest_shift] = src[i];
		++i;
	}
}

char	*copy_str_and_close(char *src, int len)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

int		append_str_and_close(char **dest, char *src, int len)
{
	int		dest_len;
	char	*temp;

	if (len > return_str_len(src))
		len = return_str_len(src);
	dest_len = return_str_len(*dest);
	temp = copy_str_and_close(*dest, dest_len);
	if (temp == NULL)
		return (-1);
	if (*dest != NULL)
		free(*dest);
	*dest = malloc(sizeof(char) * (dest_len + len + 1));
	if (*dest == NULL)
		return (-1);
	mem_copy_ds(*dest, temp, 0, dest_len);
	mem_copy_ds(*dest, src, dest_len, len);
	(*dest)[dest_len + len] = '\0';
	free(temp);
	return (0);
}

int		return_str_len(char *str)
{
	int i;

	i = 0;
	if (str != NULL)
		while (str[i] != '\0')
			++i;
	return (i);
}

int		return_line_len(char *str)
{
	int len;

	len = 0;
	while (*str != '\n' && *str != '\0')
	{
		++len;
		++str;
	}
	return (len);
}
