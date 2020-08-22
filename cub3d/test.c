/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/22 18:10:44 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parse/map.h"
#include "include/parse/settings.h"
#include <stdio.h>

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

void print_settings(t_map_settings *settings)
{
	printf(">>>settings start\n");
	printf(">>resolution\n");
	printf("width:%d\n", settings->resolution->width);
	printf("height:%d\n", settings->resolution->height);
	printf(">>textures\n");
	printf("NO:%s\n", settings->texture_no);
	printf("SO:%s\n", settings->texture_so);
	printf("WE:%s\n", settings->texture_we);
	printf("EA:%s\n", settings->texture_ea);
	printf("S:%s\n", settings->texture_s);
	// printf(">>color floor\n");
	// printf("r:%d g:%d b:%d\n", settings->color_floor->red, settings->color_floor->green, settings->color_floor->blue);
	// printf(">>color ceiling\n");
	// printf("r:%d g:%d b:%d\n", settings->color_ceiling->red, settings->color_ceiling->green, settings->color_ceiling->blue);
	// printf(">>>settings end\n");
}

int main()
{
	/*
	int **map = NULL;
	if(return_map("map_easy.cub", &map) < 0)
	{
		ft_putstr("error parse map\n");
		return (-1);
	}
	print_map(map);
	free_map(map);
	*/

	t_map_settings *settings;
	if(return_settings("map_settings.cub", &settings) == ERROR)
	{
		ft_putstr("error parse settings\n");
		return (-1);
	}
	print_settings(settings);
	//free_settings(settings);
		
	return 0;
}