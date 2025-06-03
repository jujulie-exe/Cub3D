/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 12:25:04 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"
//float perfomance(t_ray *ray)
//{
//	
//		return 1;
//	else if (ray->dtw > 0.0 && ray->dtw < 0.3)
//		return 0.7;
//	else if (ray->dtw > 0.0 && ray->dtw < 0.5)
//		return 0.5;
//	else if (ray->dtw > 0.0 && ray->dtw < 0.8)
//		return 0.3;
//	return 0.01;
//}

void	calc_dda(t_ray *ray, t_player *player, char **map, float start)
{
	float	ray_distance;

	ray->side = 0;
	while (!collision(ray, player, map))
	{
		ray_distance = perfomance(ray);
		ray->var_x += cos(start) * ray_distance;
		ray->var_y += sin(start) * ray_distance;
		if (fabs(sin(start)) >= fabs(cos(start)) && ray->var_x < ray->var_y)
			ray->side = 1;
	}
}

float	calc_dist(float x, float y)
{
	float	dst;

	dst = sqrtf(x * x + y * y);
	return (dst);
}

float	dist_to_wall(t_player *player, t_ray *ray)
{
	float	dtw;
	float	delta_x;
	float	delta_y;
	float	a;

	delta_x = ray->var_x - player->posx;
	delta_y = ray->var_y - player->posy;
	angle_calcul(player, ray, delta_x, delta_y);
	a = (atan2(delta_y, delta_x) - player->angle);
	dtw = calc_dist(delta_x, delta_y) * ((cos(a)));
	return (dtw);
}

void	angle_calcul(t_player *player, t_ray *ray, float dx, float dy)
{
	float	p_r;
	float	p_j;

	p_r = dy / dx;
	p_j = sin(player->angle) / cos(player->angle);
	ray->alpha = atan(fabs((p_j - p_r) / (1 + p_j + p_r)));
}

void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player)
{
	ray->dtw = dist_to_wall(player, ray);
	ray->height = (STEPSIZE / ray->dtw) * (mlx->width / 2);
	ray->center_line = (mlx->height - ray->height) / 2;
	ray->last_line = ray->center_line + ray->height;
}
