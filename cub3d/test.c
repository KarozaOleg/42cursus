/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaston <mgaston@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:36:37 by mgaston           #+#    #+#             */
/*   Updated: 2020/11/11 20:21:52 by mgaston          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/game/game_utils.h"
#include "include/mlx/hooks.h"
#include "include/global.h"
#include "include/mlx/draw.h"
#include "test.h"
#include <stdio.h>

int test_leaks()
{
	char *file_path = "maps/map_corridor.cub";
	t_game *game = NULL;
	
	if(return_game(file_path, &game) == ERROR)
		return 1;		

	// print_map(game->map->array);
	
	register_mlx_hook_key_pressed(game);	
	mlx_loop(game->mlx_my->mlx);

	
	
	return (cub3d_exit("", game));
}

//gcc test*.c cub3d.a -lmlx -framework OpenGL -framework AppKit
//gcc test*.c cub3d.a libmlx_Linux.a -lXext -lX11 -lm
int main()
{
	int answer = test_leaks();
	sleep(0);
	return (answer);
}


// void	ft_get_textr_coord(t_camera *ray, t_game *exe)
// {
// 	if (ray->side == 0)
// 		ray->wall_coord = exe->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
// 	else
// 		ray->wall_coord = exe->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
		
// 	ray->wall_coord -= floor(ray->wall_coord);
// 	ray->textr_coord_x = (int)(ray->wall_coord * exe->textr[exe->curr_side].width);

// 	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side != 0 && ray->ray_dir_y < 0))
// 		ray->textr_coord_x = exe->textr[exe->curr_side].width - ray->textr_coord_x - 1.0;

// 	ray->step = 1.0 * exe->textr[exe->curr_side].height / ray->line_height;
// 	ray->textr_pos = (ray->draw_start - exe->res[1] / DIST + ray->line_height / DIST) * ray->step;
// }

// void	ft_get_textr_color(t_camera *ray, t_game *exe)
// {
// 	int start;
// 	int color;

// 	start = ray->draw_start - 1;
// 	ft_get_textr_coord(ray, exe);
// 	while (++start < ray->draw_end)
// 	{
// 		ray->textr_coord_y = (int)ray->textr_pos & (exe->textr[exe->curr_side].width - 1);
// 		ray->textr_pos += ray->step;
		
// 		color = ft_get_color_z(exe->textr[exe->curr_side], ray->textr_coord_x, ray->textr_coord_y);
// 		ft_my_pixel_put(exe, ray->x, start, color);
// 	}
// }

// int		ft_get_color_z(t_image textr, int x, int y)
// {
// 	char	*dst;
// 	int		color;

// 	dst = textr.addr + (y * textr.line_length +
// 	x * (textr.bits_per_pixel / 8));
// 	color = *(unsigned int*)dst;
// 	return (color);
// }
// absolute direction from the player to the sprite (in radians)
/*
void draw_sprite(Sprite &sprite, std::vector<float> &depth_buffer, FrameBuffer &fb, Player &player, Texture &tex_sprites) {
    // absolute direction from the player to the sprite (in radians)
    float sprite_dir = atan2(sprite.y - player.y, sprite.x - player.x);
    while (sprite_dir - player.a >  M_PI) sprite_dir -= 2*M_PI; // remove unncesessary periods from the relative direction
    while (sprite_dir - player.a < -M_PI) sprite_dir += 2*M_PI;

    float sprite_dist = std::sqrt(pow(player.x - sprite.x, 2) + pow(player.y - sprite.y, 2)); // distance from the player to the sprite
    size_t sprite_screen_size = std::min(1000, static_cast<int>(fb.h/sprite_dist)); // screen sprite size
    int h_offset = (sprite_dir - player.a)/player.fov*(fb.w/2) + (fb.w/2)/2 - tex_sprites.size/2; // do not forget the 3D view takes only a half of the framebuffer
    int v_offset = fb.h/2 - sprite_screen_size/2;

    for (size_t i=0; i<sprite_screen_size; i++) {
        if (h_offset+int(i)<0 || h_offset+i>=fb.w/2) continue;
        if (depth_buffer[h_offset+i]<sprite_dist) continue; // this sprite column is occluded
        for (size_t j=0; j<sprite_screen_size; j++) {
            if (v_offset+int(j)<0 || v_offset+j>=fb.h) continue;
            uint32_t color = tex_sprites.get(i*tex_sprites.size/sprite_screen_size, j*tex_sprites.size/sprite_screen_size, sprite.tex_id);
            uint8_t r,g,b,a;
            unpack_color(color, r, g, b, a);
            if (a>128)
            fb.set_pixel(fb.w/2 + h_offset+i, v_offset+j, color);
        }
    }
}
*/