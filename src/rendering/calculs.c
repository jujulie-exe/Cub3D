/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/28 17:01:43 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	calc_dda(t_ray *ray, t_player *player, char **map)
{
	while (!collision(player, map))
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
	a = atan2(delta_y, delta_x) - player->angle;
	dtw = calc_dist(delta_x, delta_y) * cos(a);
	return (dtw);
}

void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player)
{
	ray->dtw = dist_to_wall(player, ray);
	ray->height = (STEPSIZE / ray->dtw) * (mlx->width / 2);
	ray->center_line = (mlx->height - ray->height) / 2;
	ray->last_line = ray->center_line + ray->height;
}
