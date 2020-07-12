/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:07:53 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/12 16:45:01 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MAXIMUM_FD 1024

int		get_next_line(int fd, char **line);
int		append_str_and_close(char **dest, char *src, int len);
int		return_str_len(char *str);
char	*copy_str_and_close(char *src, int len);
int		return_line_len(char *str);

#endif
