/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/04 19:04:05 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	init_vector(t_ray *ray, t_player *player, float start)
{
	(void)start;
	ray->map_x = (int)player->posx;
	ray->map_y = (int)player->posy;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = side(player, ray, 1);
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = side(player, ray, 2);
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = side(player, ray, 3);
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = side(player, ray, 4);
	}
}

void	calc_dda(t_ray *ray, t_player *player, char **map, float start)
{
	init_vector(ray, player, start);
	while (!collision(ray, player, map))
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->dtw = (ray->map_x - player->posx
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->dtw = (ray->map_y - player->posy
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

float	calc_dist(float x, float y)
{
	float	dst;

	dst = sqrtf(x * x + y * y);
	return (dst);
}

void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player)
{
	(void)player;
	ray->height = (mlx->height / ray->dtw);
	ray->center_line = (mlx->height - ray->height) / 2;
	ray->last_line = ray->center_line + ray->height;
}
