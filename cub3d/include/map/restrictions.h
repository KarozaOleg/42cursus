/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrictions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:40:35 by mgaston           #+#    #+#             */
/*   Updated: 2020/09/06 18:05:45 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESTRICTIONS_H
# define RESTRICTIONS_H

# include "map_essences.h"
# include "../global.h"
# include "../global_essences.h"

t_answer	return_restrictions(int **map, t_restriction ****restrictions);

#endif