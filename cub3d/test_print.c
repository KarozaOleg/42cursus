/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 12:15:28 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/30 14:18:13 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void print_settings(t_map_settings *settings)
{
	printf(">>>settings start\n");
	printf(">>resolution\n");
	printf("width:%d, height:%d\n", settings->resolution->width,settings->resolution->height);
	printf(">>textures\n");
	printf("NO:%s\n", settings->texture_no);
	printf("SO:%s\n", settings->texture_so);
	printf("WE:%s\n", settings->texture_we);
	printf("EA:%s\n", settings->texture_ea);
	printf("S:%s\n", settings->texture_s);
	printf(">>color floor\n");
	printf("r:%d g:%d b:%d\n", settings->color_floor->red, settings->color_floor->green, settings->color_floor->blue);
	printf(">>color ceiling\n");
	printf("r:%d g:%d b:%d\n", settings->color_ceiling->red, settings->color_ceiling->green, settings->color_ceiling->blue);
	printf(">>>settings end\n");
}

void print_map(int **map)
{
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
}