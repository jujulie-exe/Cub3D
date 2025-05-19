/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/19 15:02:44 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	calc_dda(t_ray *ray, t_player *player, char **map, float start)
{
	while (!collision(ray, player, map))
	{
		ray->var_x += cos(start);
		ray->var_y += sin(start);
	}
}

float	calc_dist(float x, float y)
{
	float	dst;

	dst = sqrtf(x * x + y * y);
	return (dst);
}

float	dist_to_wall(t_player *player, t_ray *ray, float start)
{
	float	dtw;
	float	delta_x;
	float	delta_y;
	float	a;

	delta_x = ray->var_x - player->posx;
	delta_y = ray->var_y - player->posy;
	a = atan2(delta_y, delta_x) - start;
	dtw = calc_dist(delta_x, delta_y) * cos(a);
	//printf("x = %f; y = %f; dst = %f\n", delta_x,delta_y, dtw);
	return (dtw);
}

void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player, float start)
{
	ray->dtw = dist_to_wall(player, ray, start);
	ray->height = (STEPSIZE / ray->dtw) * (mlx->width / 2);
	ray->center_line = (mlx->height - ray->height) / 2;
	ray->last_line = ray->center_line + ray->height;
}
