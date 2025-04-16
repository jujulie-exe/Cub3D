/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/16 14:45:41 by iwaslet          ###   ########.fr       */
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
	ray->height = (STEPSIZE / dtw) * (largeur_fenetre_dqns_mlx / 2);
	ray->closest_line = (hauteur_fenetre - ray->height) / 2;
	ray->last_line = ray->closest_line + ray->height;
	return (ray->last_line - ray->closest_line);
}
