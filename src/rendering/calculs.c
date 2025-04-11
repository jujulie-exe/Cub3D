/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/11 18:35:54 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

void	calc_dda(t_ray *ray, t_player *player, char **map)
{
	while (!collision(ray, player, map))
	{
		ray->var_x += cos(player->angle);
		ray->var_y += sin(player->angle);
	}
}

float	calc_dist(float x, float y)
{
	float	dst;

	dst = sqrt(x * x + y * y);
	return (dst);
}

float	dist_to_wall(t_player *player, t_ray *ray)
{
	float	dtw;
	float	delta_x;
	float	delta_y;
	float	a;

	delta_x = ray->var_x - player->x;
	delta_y = ray->var_y - player->y;
	a = atan2(delts_y, delta_x) - player->angle;
	dtw = calc_dist(delta_x, delta_y) * cos(a);
	return (dtw);
}

int	calc_height(t_ray *ray, t_player *player)
{
	ray->dtw = dist_to_wall(player, ray);
	ray->height = (BLOCKSIZE / dtw) * (largeur_fenetre_dqns_mlx / 2);
	ray->closest_line = (hauteur_fenetre - ray->height) / 2;
	ray->last_line = ray->closest_line + ray->height;
	return (ray->last_line - ray->closest_line);
}

//while (ray->closest_line < ray->last_line)
//{put_pixel(dessiner le mur) ; ray->closest_line++}

// if(!DEBUG)
// {
// 	float dist = fixed_dist(player->x, player->y, ray_x, ray_y, game);
// 	float height = (BLOCK / dist) * (WIDTH / 2);
// 	int start_y = (HEIGHT - height) / 2;
// 	int end = start_y + height;
// 	while(start_y < end)
// 	{
// 		put_pixel(i, start_y, 255, game);
// 		start_y++;
// 	}

// int draw_loop(t_game *game)
// {
//     t_player *player = &game->player;
//     move_player(player);
//     clear_image(game);
//     if(DEBUG)
//     {
//         draw_square(player->x, player->y, 10, 0x00FF00, game);
//         draw_map(game);
//     }
//     float fraction = PI / 3 / WIDTH;
//     float start_x = player->angle - PI / 6;
//     int i = 0;
//     while(i < WIDTH)
//     {
//         draw_line(player, game, start_x, i);
//         start_x += fraction;
//         i++;
//     }
//     mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
//     return 0;
// }