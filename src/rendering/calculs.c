/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:27:22 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/27 18:43:03 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	calc_dda(t_ray *ray, t_player *player, char **map, float start)
{
	while (!collision(ray, player, map))
	{
		ray->var_x += cos(start) * 0.001;
		ray->var_y += sin(start) * 0.001;
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

	//projection(player, ray);
	delta_x = ray->var_x - player->posx;
	delta_y = ray->var_y - player->posy;
	angle_calcul(player, ray, delta_x, delta_y);
	// delta_x = ray->var_x - ray->proj_x;
	// delta_y = ray->var_y - ray->proj_y;
	a = (atan2(delta_y, delta_x) - start);
	//printf("alpha is %f \n", cos(ray->alpha));
	dtw = calc_dist(delta_x, delta_y) * ((cos(ray->alpha)));
	printf("dtw = %f\n", dtw);
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

// void	projection(t_player *player, t_ray *ray)
// {
// 	float	tg;
// 	float	f;

// 	tg = tan(player->angle);
// 	f = (1 / (tg + 1 / tg));
// 	ray->proj_x = f * ((-1) * player->posy + player->posx / tg
// 			- ray->var_y + tg * ray->var_x);
// 	ray->proj_y = (tg * f) * (ray->proj_x) + ray->var_y
// 		+ tg * ray->var_x;
// }

void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player, float start)
{
	ray->dtw = dist_to_wall(player, ray, start);
	ray->height = (STEPSIZE / ray->dtw) * (mlx->width / 2);
	ray->center_line = (mlx->height - ray->height) / 2;
	ray->last_line = ray->center_line + ray->height;
}

/*plutot que de calculer la dist p/r au joueur,
la calculer p/r a une droite perpendiculaire au joueur*/