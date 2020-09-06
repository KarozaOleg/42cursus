/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:23:49 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 12:21:14 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_H
# define TEST_H

#include <stdio.h>
#include <unistd.h>
#include "include/map/map_essences.h"

void print_settings(t_map_settings *settings);
void print_map(int **map);

#endif