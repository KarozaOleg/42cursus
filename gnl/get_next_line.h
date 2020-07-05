/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:07:53 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/05 14:16:22 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define MAXIMUM_FD 1024

int		get_next_line(int fd, char **line);
int		append_str_and_close(char **dest, char *src, int len);
int		return_str_len(char *str);
char	*copy_str_and_close(char *src, int len);
int		return_line_len(char *str);

#endif
