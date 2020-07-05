/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:50:24 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/05 14:18:37 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_newline_char_exist(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	mem_copy_ss(char *dest, char *src, int src_shift, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i + src_shift];
		++i;
	}
}

int		cut_str(char **str, int len)
{
	char	*temp;
	int		bytes_to_copy;

	if (*str == NULL)
		return (-1);
	temp = copy_str_and_close(*str, return_str_len(*str));
	if (temp == NULL)
		return (-1);
	bytes_to_copy = return_str_len(*str);
	free(*str);
	if (bytes_to_copy < 1)
	{
		*str = NULL;
		return (0);
	}
	*str = malloc(sizeof(char) * (bytes_to_copy + 1));
	if (*str == NULL)
		return (-1);
	mem_copy_ss(*str, temp, len, bytes_to_copy);
	(*str)[bytes_to_copy] = '\0';
	free(temp);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buff[MAXIMUM_FD];
	char		temp[BUFFER_SIZE + 1];
	int			bytes_readed;
	int			line_len;

	if (fd < 0 || line == NULL || fd >= MAXIMUM_FD)
		return (-1);
	*line = copy_str_and_close("", 0);
	line_len = 0;
	while ((bytes_readed = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[bytes_readed] = '\0';
		if (append_str_and_close(&buff[fd], temp, bytes_readed) < 0)
			return (-1);
		if (is_newline_char_exist(buff[fd]) > 0)
			break ;
	}
	line_len = return_line_len(buff[fd]);
	if (append_str_and_close(line, buff[fd], line_len) < 0)
		return (-1);
	if (buff[fd] == NULL)
		return (0);
	return (cut_str(&buff[fd], line_len + is_newline_char_exist(buff[fd])));
}
