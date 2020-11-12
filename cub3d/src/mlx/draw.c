/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 14:20:22 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/12 21:53:05 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mlx/draw.h"
#include <math.h>
#include "../../include/mlx/texture.h"

//TODO remove
#include <stdio.h>

typedef struct	s_image
{
	unsigned int	*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				endl;
}				t_image;

void	draw_scaled_point(t_mlx_img *scene, int x_shifted, int y_shifted, int scaled_to, int color)
{
	int y = y_shifted;
	int y_amount = 0;
	while(y_amount < scaled_to)
	{
		int x = x_shifted;
		int x_amount = 0;
		while(x_amount < scaled_to)
		{
			my_mlx_pixel_put(scene, x, y, color);
			x_amount += 1;
			x += 1;
		}
		y_amount += 1;
		y += 1;
	}
}

void	draw_line(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color)
{
	int x;
	int y;
	int dx;
	int dy;
	int dx1;
	int dy1;
	int px;
	int py;
	int xe;
	int ye;
	int i;
 	dx=x2-x1;
	dy=y2-y1;
	dx1=abs(dx);
	dy1=abs(dy);
	px=2*dy1-dx1;
	py=2*dx1-dy1;
	if(dy1<=dx1)
	{
		if(dx>=0)
		{
			x=x1;
			y=y1;
			xe=x2;
		}
		else
		{
			x=x2;
			y=y2;
			xe=x1;
		}

		my_mlx_pixel_put(scene, x, y, color);
		for(i=0;x<xe;i++)
		{
			x=x+1;
			if(px<0)
			{
				px=px+2*dy1;
			}
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
				{
					y=y+1;
				}
				else
				{
					y=y-1;
				}
				px=px+2*(dy1-dx1);
			}
			my_mlx_pixel_put(scene, x, y, color);
		}
	}
	else
	{
		if(dy>=0)
		{
			x=x1;
			y=y1;
			ye=y2;
		}
		else
		{
			x=x2;
			y=y2;
			ye=y1;
		}		
		my_mlx_pixel_put(scene, x, y, color);
		for(i=0;y<ye;i++)
		{
			y=y+1;
			if(py<=0)
			{
				py=py+2*dx1;
			}
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
				{
					x=x+1;
				}
				else
				{
					x=x-1;
				}
				py=py+2*(dx1-dy1);
			}
			my_mlx_pixel_put(scene, x, y, color);
		}
	}
}

void	draw_rays(int **map, t_mlx_img *scene, t_player *player, int scaled_to)
{	
	int i_ray = 0;
	float ray_angle = player->pov - (player->fov / 2.0);
	while(i_ray < player->num_rays)
	{
		float x2 = player->x;
		float y2 = player->y;
		float x2_possible = player->x;
		float y2_possible = player->y;
		while(map[(int)(y2_possible / ((float)scaled_to))][(int)(x2_possible / ((float)scaled_to))] != 1)
		{
			x2_possible += cos(ray_angle);
			y2_possible += sin(ray_angle);
			
			if(map[(int)(y2_possible / ((float)scaled_to))][(int)(x2_possible / ((float)scaled_to))] != 1)
			{				
				x2 += cos(ray_angle);
				y2 += sin(ray_angle);
			}
		}
				
		draw_line(scene, player->x, x2, player->y, y2, return_yellow());		
		i_ray += 1;
		ray_angle += player->fov / (float)player->num_rays;
	}
}

void	draw_player(t_mlx_img *scene, t_player *player)
{
	my_mlx_pixel_put(scene, player->x, player->y, player->color);
}

void	draw_map(t_mlx_img *scene, int **map, int scaled_to)
{		
	int y = 0;
	while(map[y] != NULL)
	{
		int x = 0;
		while(map[y][x] > -1)
		{
			if(map[y][x] == 1)
				// my_mlx_pixel_put(scene, x, y, return_white());
				draw_scaled_point(scene, x * scaled_to, y * scaled_to, scaled_to, return_white());
			else
				// my_mlx_pixel_put(scene, x, y, return_black());
				draw_scaled_point(scene, x * scaled_to, y * scaled_to, scaled_to, return_black());
			x += 1;
		}
		y += 1;
	}
}

int		abs(int value)
{
	if(value < 1)
		value *= -1;
	return value;
}

void	clear(t_mlx_img *scene, t_map_settings *map_settings)
{		
	int y = 0;
	while(y < map_settings->resolution->height)
	{
		int x = 0;
		while(x < map_settings->resolution->width)
		{
			my_mlx_pixel_put(scene, x, y, return_black());
			x += 1;
		}
		y += 1;
	}
}

void	draw_square(t_mlx_img *scene, int x1, int x2, int y1, int y2, int color)
{
	while(x1 < x2)
	{
		while(y1 < y2)
		{			
			my_mlx_pixel_put(scene, x1, y1, color);
			y1 += 1;
		}
		x1 += 1;
	}	
}

float	normalize_angle(float angle) 
{
   angle = remainder(angle, PI * 2);
    if (angle < 0) {
        angle = PI * 2 + angle;
    }
    return angle;
}

float distance_between_points(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

t_bool map_has_wall_at(t_game *game, float x, float y) {
    if (x < 0 || 
		x > game->map_settings->resolution->width || 
		y < 0 || 
		y > game->map_settings->resolution->height) 
	{
        return TRUE;
    }
	
    int map_grid_index_x = (int)floor(x / (float)game->map->scaled_to);
    int map_grid_index_y = (int)floor(y / (float)game->map->scaled_to);
	
    if(game->map->array[map_grid_index_y][map_grid_index_x] == 1)
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	return_y_amount(int **array)
{
	int amount;
	
	amount = 0;
	while(array[amount] != NULL)
		amount++;
	return (amount);
}

int return_x_amount(int *array)
{
	int amount;
	
	amount = 0;
	while(array[amount] > -1)
		amount++;
	return (amount);
}

void ray_cast_horisontal(t_game *game, t_ray *ray, t_ray_cast_result *cast_result)
{	
	float xstep;
	float ystep;
	float xintercept;
	float yintercept;

	cast_result->wall_hit_x = 0;
	cast_result->wall_hit_y = 0;
	cast_result->wall_content = 0;
	cast_result->wall_hit = FALSE;
	
    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = floor(game->player->y / game->map->scaled_to) * game->map->scaled_to;
    yintercept += ray->is_ray_facing_down ? game->map->scaled_to : 0;

    // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = game->player->x + (yintercept - game->player->y) / tan(ray->angle);

    // Calculate the increment xstep and ystep
    ystep = game->map->scaled_to;
    ystep *= ray->is_ray_facing_up ? -1 : 1;

    xstep = game->map->scaled_to / tan(ray->angle);
    xstep *= (ray->is_ray_facing_left && xstep > 0) ? -1 : 1;
    xstep *= (ray->is_ray_facing_right && xstep < 0) ? -1 : 1;

    float nextHorzTouchX = xintercept;
    float nextHorzTouchY = yintercept;

	int y_amount = return_y_amount(game->map->array);

    // Increment xstep and ystep until we find a wall
    while (nextHorzTouchX >= 0 && 
			nextHorzTouchX <= game->map_settings->resolution->width && 
			nextHorzTouchY >= 0 && 
			nextHorzTouchY <= game->map_settings->resolution->height) 
	{
        float xToCheck = nextHorzTouchX;
        float yToCheck = nextHorzTouchY + (ray->is_ray_facing_up ? -1 : 0);

		if((int)floor(yToCheck / game->map->scaled_to) >= y_amount)
			break;
		if((int)floor(xToCheck / game->map->scaled_to) >= return_x_amount(game->map->array[(int)floor(yToCheck / game->map->scaled_to)]))
			break;

        if (map_has_wall_at(game, xToCheck, yToCheck) == TRUE) 
		{
			cast_result->wall_hit_x = nextHorzTouchX;
			cast_result->wall_hit_y = nextHorzTouchY;
			cast_result->wall_content = game->map->array[(int)floor(yToCheck / game->map->scaled_to)][(int)floor(xToCheck / game->map->scaled_to)];
            cast_result->wall_hit = TRUE;
            break;
        } 
		else 
		{
            nextHorzTouchX += xstep;
            nextHorzTouchY += ystep;
        }
    }
}

void ray_cast_vertical(t_game *game, t_ray *ray, t_ray_cast_result *cast_result)
{	
	float xstep;
	float ystep;
	float xintercept;
	float yintercept;

	cast_result->wall_hit_x = 0;
	cast_result->wall_hit_y = 0;
	cast_result->wall_content = 0;
	cast_result->wall_hit = FALSE;

    // Find the x-coordinate of the closest vertical grid intersection
    xintercept = floor(game->player->x / game->map->scaled_to) * game->map->scaled_to;
    xintercept += ray->is_ray_facing_right ? game->map->scaled_to : 0;

    // Find the y-coordinate of the closest vertical grid intersection
    yintercept = game->player->y + (xintercept - game->player->x) * tan(ray->angle);

    // Calculate the increment xstep and ystep
    xstep = game->map->scaled_to;
    xstep *= ray->is_ray_facing_left ? -1 : 1;

    ystep = game->map->scaled_to * tan(ray->angle);
    ystep *= (ray->is_ray_facing_up && ystep > 0) ? -1 : 1;
    ystep *= (ray->is_ray_facing_down && ystep < 0) ? -1 : 1;

    float nextVertTouchX = xintercept;
    float nextVertTouchY = yintercept;

	int y_amount = return_y_amount(game->map->array);

    // Increment xstep and ystep until we find a wall
    while (nextVertTouchX >= 0 && 
			nextVertTouchX <= game->map_settings->resolution->width &&
			nextVertTouchY >= 0 && 
			nextVertTouchY <= game->map_settings->resolution->height) 
	{
        float xToCheck = nextVertTouchX + (ray->is_ray_facing_left ? -1 : 0);
        float yToCheck = nextVertTouchY;

		if((int)floor(yToCheck / game->map->scaled_to) >= y_amount)
			break;
		if((int)floor(xToCheck / game->map->scaled_to) >= return_x_amount(game->map->array[(int)floor(yToCheck / game->map->scaled_to)]))
			break;

        if (map_has_wall_at(game, xToCheck, yToCheck) == TRUE) 
		{
			cast_result->wall_hit_x = nextVertTouchX;
			cast_result->wall_hit_y = nextVertTouchY;
			cast_result->wall_content = game->map->array[(int)floor(yToCheck / game->map->scaled_to)][(int)floor(xToCheck / game->map->scaled_to)];
			cast_result->wall_hit = TRUE;
            break;
        } 
		else 
		{
            nextVertTouchX += xstep;
            nextVertTouchY += ystep;
        }
    }
}

t_answer cast_ray(t_game *game, t_ray *ray) 
{
	t_ray_cast_result *cast_result_horisontal;
	t_ray_cast_result *cast_result_vertical;
	
	cast_result_horisontal = malloc(sizeof(*cast_result_horisontal));
	if(cast_result_horisontal == NULL)
		return (ERROR);

	ray_cast_horisontal(game, ray, cast_result_horisontal);

	cast_result_vertical = malloc(sizeof(*cast_result_vertical));
	if(cast_result_vertical == NULL)
		return (ERROR);	
		
	ray_cast_vertical(game, ray, cast_result_vertical);
	
    // Calculate both horizontal and vertical hit distances and choose the smallest one
    float horzHitDistance = cast_result_horisontal->wall_hit == TRUE
        ? distance_between_points(game->player->x, game->player->y,cast_result_horisontal->wall_hit_x, cast_result_horisontal->wall_hit_y)
        : 340282346638528859811704183484516925440.0;
    float vertHitDistance = cast_result_vertical->wall_hit == TRUE
        ? distance_between_points(game->player->x, game->player->y, cast_result_vertical->wall_hit_x, cast_result_vertical->wall_hit_y)
        : 340282346638528859811704183484516925440.0;

    if (vertHitDistance < horzHitDistance) 
	{
		ray->distance = vertHitDistance;
		ray->wall_hit_x = cast_result_vertical->wall_hit_x;
		ray->wall_hit_y = cast_result_vertical->wall_hit_y;
		ray->wall_hit_content = cast_result_vertical->wall_content;
		ray->was_hit_vertical = TRUE;
    } 
	else 
	{
		ray->distance = horzHitDistance;
		ray->wall_hit_x = cast_result_horisontal->wall_hit_x;
		ray->wall_hit_y = cast_result_horisontal->wall_hit_y;
		ray->wall_hit_content = cast_result_horisontal->wall_content;
		ray->was_hit_vertical = FALSE;
    }

	return (SUCCESS);
}

typedef struct s_sprite
{	
	int x;
	int y;
	float sprite_dir;
	float sprite_dist;
	int sprite_screen_size;
	int h_offset;
	int v_offset;
}				t_sprite;

#define sprite_amount 3
t_sprite *sprite[sprite_amount];
t_bool sprites_loaded = FALSE;
t_image *sprite_texture;


#define wall_amount 4
t_image *wall[wall_amount];
t_bool walls_loaded = FALSE;

int return_texture_color(t_image *texture, int x, int y)
{
	char	*dst;
	int		color;
		
	dst = texture->addr + (y * texture->sl + x * (texture->bpp / 8));
	color = *(unsigned int*)dst;

	return (color);
}

void	sprite_calculate(t_game *game, t_sprite *sprite)
{
	t_player *player = game->player;	
	int x = sprite->x * game->map->scaled_to;	
	int y = sprite->y * game->map->scaled_to;
	
	sprite->sprite_dir = atan2(y - player->y, x - player->x);	
    sprite->sprite_dist = sqrt(pow(player->x/game->map->scaled_to - x/game->map->scaled_to, 2) + pow(player->y/game->map->scaled_to - y/game->map->scaled_to, 2));
    sprite->sprite_screen_size = game->map_settings->resolution->height/sprite->sprite_dist;
	if (sprite->sprite_screen_size > game->map_settings->resolution->height * 2)
		sprite->sprite_screen_size = game->map_settings->resolution->height * 2;
    sprite->h_offset = (sprite->sprite_dir - player->pov)*(game->map_settings->resolution->width)/(float)(player->fov) + game->map_settings->resolution->width/2 - sprite->sprite_screen_size/2;
	sprite->v_offset = game->map_settings->resolution->height/2.0 - sprite->sprite_screen_size/2;
}

void	draw_sprite(t_game *game, t_sprite *sprite, float *depth_buffer)
{    
	for (int i=0; i < sprite->sprite_screen_size; i++) 
	{
        if (sprite->h_offset+i<0 || sprite->h_offset+i >= game->map_settings->resolution->width) 
			continue;
		if(depth_buffer[sprite->h_offset+i] < sprite->sprite_dist)
			continue;
		
        for (int j=0; j < sprite->sprite_screen_size; j++) 
		{
            if (sprite->v_offset+j<0 || sprite->v_offset+j >= game->map_settings->resolution->height) 
				continue;	
				
			int texture_x = i*64/sprite->sprite_screen_size;
			int texture_y = j*64/sprite->sprite_screen_size;
			int color = return_texture_color(sprite_texture, texture_x, texture_y);
			if(color == 0x0)
				continue;
			
			int x = game->map_settings->resolution->width + sprite->h_offset+i;
			int y = sprite->v_offset+j;
				
			my_mlx_pixel_put(game->mlx_my->scene, x, y, color);			
        }
    }
}

t_answer	draw_projection_plane_ddp(t_game *game)
{
	t_player *player = game->player;
	t_ray *ray;

	if(sprites_loaded == FALSE)
	{
		int width;
		int height;

		char *texture_name = "textures/barrel.xpm";
		sprite_texture = malloc(sizeof(*(sprite_texture)));
		sprite_texture->img = mlx_xpm_file_to_image(game->mlx_my->mlx, texture_name, &width, &height);
		sprite_texture->addr = (char *)mlx_get_data_addr(sprite_texture->img, &(sprite_texture->bpp), &(sprite_texture->sl), &(sprite_texture->endl));
		
		int i = 0;
		while(i < sprite_amount)
		{		
			sprite[i] = malloc(sizeof(*sprite[i]));

			sprite[i]->x = 5;
			sprite[i]->y = i + 5;			
			
			i += 1;
		}
		sprites_loaded = TRUE;
	}

	if(walls_loaded == FALSE)
	{
		int width;
		int height;
		
		int i = 0;
		while(i < wall_amount)
		{
			char *texture_name;
			if(i == 0)
				texture_name = "textures/wall_0.xpm";
			else if(i == 1)
				texture_name = "textures/wall_1.xpm";
			else if(i == 2)
				texture_name = "textures/wall_2.xpm";
			else if(i == 3)
				texture_name = "textures/wall_3.xpm";

			wall[i] = malloc(sizeof(*wall[i]));
			wall[i]->img = mlx_xpm_file_to_image(game->mlx_my->mlx, texture_name, &width, &height);
			wall[i]->addr = (char *)mlx_get_data_addr(wall[i]->img, &(wall[i]->bpp), &(wall[i]->sl), &(wall[i]->endl));

			i += 1;
		}
		walls_loaded = TRUE;
	}

	ray = malloc(sizeof(*ray));
	if(ray == NULL)
		return ERROR;

	float ray_angle = game->player->pov - (game->player->fov / 2.0);
	int ray_index = 0;	

	float depth_buffer[game->player->num_rays];

	while(ray_index < game->player->num_rays)
	{
		ray->angle = normalize_angle(ray_angle);
		
		ray->is_ray_facing_down = ray->angle > 0 && ray->angle < PI;
		ray->is_ray_facing_up = !ray->is_ray_facing_down;

		ray->is_ray_facing_right = ray->angle < 0.5 * PI || ray->angle > 1.5 * PI;
		ray->is_ray_facing_left = !ray->is_ray_facing_right;
		
		if(cast_ray(game, ray) == ERROR)
			return (ERROR);
		
		float dist = ray_index*cos(ray->angle - game->player->pov);
        depth_buffer[ray_index] = dist;
			
		float perpDistance = ray->distance * cos(ray->angle - game->player->pov);
        float distanceProjPlane = (game->map_settings->resolution->width / 2) / tan(game->player->fov / 2);
        float projectedWallHeight = (game->map->scaled_to / perpDistance) * distanceProjPlane;
		
        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (game->map_settings->resolution->height / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;
		
        int wallBottomPixel = (game->map_settings->resolution->height / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > game->map_settings->resolution->height ? game->map_settings->resolution->height : wallBottomPixel;
		
		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			0,
			wallTopPixel,
			CEILING);		
		
		int textureOffsetX;
        if (ray->was_hit_vertical)
            textureOffsetX = (int)ray->wall_hit_y % 64;
        else
            textureOffsetX = (int)ray->wall_hit_x % 64;
		
		int texture_id;
		if(ray->was_hit_vertical)
		{
			if((ray->angle > PI/2 && ray->angle < PI) || (ray->angle > PI && ray->angle < PI+PI/2))
				texture_id = 1;
			else if((ray->angle > 0 && ray->angle < PI/2) || (ray->angle > PI+PI/2 && ray->angle < 2*PI))
				texture_id = 2;			
		}
		else
		{
			if(ray->angle > 0 && ray->angle < PI)
				texture_id = 0;	
			else if(ray->angle > PI && ray->angle < 2*PI)
				texture_id = 3;
		}
			
        for (int y = wallTopPixel; y < wallBottomPixel; y++) 
		{			
			int distanceFromTop = y + (wallStripHeight / 2) - (game->map_settings->resolution->height / 2);
			int textureOffsetY = distanceFromTop * ((float)64 / wallStripHeight);			
			
			draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			y,
			y + 1,
			return_texture_color(wall[texture_id], textureOffsetX, textureOffsetY));
        }

		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			wallBottomPixel,
			game->map_settings->resolution->height,
			FLOOR);

		ray_angle += player->fov / ((float)player->num_rays);
		ray_index += 1;
	}

	int sprite_i = 0;
	while(sprite_i < sprite_amount)
	{
		sprite_calculate(game, sprite[sprite_i]);
		for (int i=0; i < sprite[sprite_i]->sprite_screen_size; i++) 
		{
			if (sprite[sprite_i]->h_offset+i<0 || sprite[sprite_i]->h_offset+i >= game->map_settings->resolution->width) 
				continue;

			for (int j=0; j < sprite[sprite_i]->sprite_screen_size; j++) 
			{
				if (sprite[sprite_i]->v_offset+j<0 || sprite[sprite_i]->v_offset+j >= game->map_settings->resolution->height) 
					continue;	
						
				int texture_x = i*64/sprite[sprite_i]->sprite_screen_size;
				int texture_y = j*64/sprite[sprite_i]->sprite_screen_size;
				int color = return_texture_color(sprite_texture, texture_x, texture_y);
				if(color == 0x0)
					continue;

				if(depth_buffer[sprite[sprite_i]->h_offset+i] > sprite[sprite_i]->sprite_dist)
					depth_buffer[sprite[sprite_i]->h_offset+i] = sprite[sprite_i]->sprite_dist;

			}
		}
		
		sprite_i += 1;
	}

	sprite_i = 0;
	while(sprite_i < sprite_amount)
	{
		draw_sprite(game, sprite[sprite_i], depth_buffer);
		
		sprite_i += 1;
	}
	
	return (SUCCESS);
}

void	draw_projection_plane(t_game *game)
{	
	t_map *map = game->map;
	t_player *player = game->player;

	float ray_angle = game->player->pov - (game->player->fov / 2.0);
	int ray_index = 0;
	
	while(ray_index < game->player->num_rays)
	{
		float x_possible = (float)player->x;
		float x = (float)player->x;
		float y_possible = (float)player->y;
		float y = (float)player->y;

		while(map->array[(int)(y_possible / ((float)map->scaled_to))][(int)(x_possible / ((float)map->scaled_to))] != 1)
		{
			x_possible += cos(ray_angle) / 5;
			y_possible += sin(ray_angle) / 5;
			
			if(map->array[(int)(y_possible / ((float)map->scaled_to))][(int)(x_possible / ((float)map->scaled_to))] != 1)
			{
				x = x_possible;
				y = y_possible;
			}
		}		
		
		float ray_distance = sqrt(pow(((float)player->x) - x, 2) + pow(((float)player->y) - y, 2));

		float distance_proj_plane = ((((float)game->map_settings->resolution->width) / 2.0)) / tan(game->player->fov / 2.0);
		float wall_height = (((float)map->scaled_to) / ray_distance) * distance_proj_plane;
		
		if(wall_height > (float)game->map_settings->resolution->height)
			wall_height  = (float)game->map_settings->resolution->height;
		
		float value = (((float)game->map_settings->resolution->height) / 2.0) - (wall_height / 2.0);

		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			0,
			value,
			CEILING);
			
		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			value,
			value + wall_height,
			WHITE);

		draw_square(
			game->mlx_my->scene,
			ray_index,
			ray_index + 1,
			value + wall_height,
			game->map_settings->resolution->height,
			FLOOR);
		
		ray_angle += player->fov / ((float)player->num_rays);
		ray_index += 1;
	}
}

int		draw_scene(t_game *game)
{		

	// clear(game->mlx_my->scene, game->map_settings);

	if(draw_projection_plane_ddp(game) == ERROR)
		return 0;
	
	// draw_map(game->mlx_my->scene, game->map->array, game->map->scaled_to * game->map->minimap_ratio);
	// draw_player(game->mlx_my->scene, game->player);
	// draw_rays(game->map->array, game->mlx_my->scene, game->player, game->map->scaled_to * game->map->minimap_ratio);

	// draw_projection_plane(game);

	
		
	return (mlx_put_image_to_window(game->mlx_my->mlx, game->mlx_my->win, game->mlx_my->scene->img, 0, 0));
}
