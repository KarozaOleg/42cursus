/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:36:48 by mgaston           #+#    #+#             */
/*   Updated: 2020/07/23 13:51:19 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_pattern
{
	int	flag;
	int	precision;
}				t_pattern;

int				ft_printf(const char *str, ...);
int				printer(char conversation, t_list *patterns, va_list argptr);

char			return_if_flag(char c);
char			return_if_conversion(char c);

int				free_patterns(t_list **patterns);
int				parse_patterns(int *i, const char *s, t_list **pat, va_list ar);

int				lenght_of_int(int nb);
int				length_of_x(unsigned int value);
int				length_of_uint(unsigned int value);
int				length_of_ulint(unsigned long int value);

int				printer_c(t_list *patterns, va_list argptr);
int				printer_s(t_list *patterns, va_list argptr);
int				printer_p(t_list *patterns, va_list argptr);
int				printer_d_i(t_list *patterns, va_list argptr);
int				printer_u(t_list *patterns, va_list argptr);
int				printer_x(t_list *patterns, va_list argptr, int is_upper_case);
int				printer_single_char(t_list *patterns, char c);

void			handle_default_flag_empty(t_list *pat, int *printed_len_of_tot);
void			handle_default_flag_minus(t_list *pat, int *printed_len_of_tot);
void			handle_default_flag_zero(t_list *pat, int *printed_len_of_tot);
void			handle_d_i_u_x_flag_zero(t_list *pat, int *printed_len_of_tot);

int				return_is_exist_flag_zero(t_list *patterns);
int				return_is_exist_flag_p(t_list *patterns);
int				return_is_exist_flag_zero_and_p(t_list *patterns);
int				return_is_exist_flag_empty_and_negative(t_list *patterns);
int				return_is_exist_flag_zero_and_negative(t_list *patterns);
int				return_is_exist_flag_p_and_negative(t_list *patterns);
int				return_is_exist_flag_p_precision(t_list *patterns);

void			extruder_default(char symbol_to_print, int amount);
#endif
