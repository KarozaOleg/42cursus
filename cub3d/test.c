/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/10 18:48:16 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/map.h"
#include <stdio.h>

int main()
{
	int **map = NULL;

	if(return_map("map_easy.cub", &map) < 0)
	{
		printf("error");
		return (1);
	}

	int x = 0;
	int y = 0;	
	while(map[x] != NULL)
	{
		y = 0;
		while(map[x][y] > -1)
		{
			printf("%d", (map[x][y]));
			++y;
		}
		printf("\n");
		++x;
	}

	if(map != NULL)
	{
		int i = 0;
		while(map[i] != NULL)
			free(map[i++]);
		free(map);
	}

	return 0;
}