/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/08/23 14:57:06 by mgaston          ###   ########.fr       */
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

void print_settings_adr(t_map_settings *settings)
{
	printf(">>>settings start\n");
	printf(">>resolution\n");
	printf("width:%p\n", settings->resolution);
	printf(">>textures\n");
	printf("NO:%p\n", settings->texture_no);
	printf("SO:%p\n", settings->texture_so);
	printf("WE:%p\n", settings->texture_we);
	printf("EA:%p\n", settings->texture_ea);
	printf("S:%p\n", settings->texture_s);
	printf(">>color floor\n");
	printf("%p\n", settings->color_floor);
	printf(">>color ceiling\n");
	printf("%p\n", settings->color_ceiling);
	printf(">>>settings end\n");
}

int main()
{
	char *file_path = "map.cub";
	
	int **map = NULL;
	if(return_map(file_path, &map) == ERROR)
	{
		ft_putstr("error, parsing map\n");
		free_map(map);
		return (-1);
	}
	if(is_map_valid(map) == ERROR)
	{
		ft_putstr("error, map is invalid\n");
		free_map(map);
		return (-1);
	}
	print_map(map);
	free_map(map);

	t_map_settings *settings;
	if(return_settings(file_path, &settings) == ERROR)
	{
		ft_putstr("error, parsing settings\n");
		free_settings(settings);
		return (-1);
	}
	if(is_settings_valid(settings) == ERROR)
	{
		ft_putstr("error, settings is invalid\n");
		free_settings(settings);
		return (-1);
	}

	print_settings(settings);
	free_settings(settings);
		
	return 0;
}