/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:33:05 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 17:31:22 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	init_ray(t_ray *ray)
{
	ray->var_x = 0;
	ray->var_y = 0;
	ray->proj_x = 0;
	ray->proj_y = 0;
	ray->dtw = 0;
	ray->height = 0;
	ray->center_line = 0;
	ray->last_line = 0;
	ray->side = 0;
}

int	collision(t_ray *ray, t_player *player, char **map)
{
	int	x;
	int	y;

	(void)player;
	if (ray->var_x >= 0 && ray->var_y >= 0)
	{
		x = (int)(ray->var_x);
		y = (int)(ray->var_y);
		if (map[y][x] != '1')
			return (0);
	}
	return (1);
}

void	angle_protect(float *a)
{
	if (*a > 2 * (float)PI)
		*a = 0;
	if (*a < 0)
		*a = 2 * (float)PI;
}

float	perfomance(t_ray *ray)
{
	float	d;
	float	k;
	float	calc;

	d = fmaxf(ray->dtw, 0.001f);
	k = 0.028f;
	calc = fminf(1.0f, k / sqrtf(d));
	if (calc <= 0.01)
		return (0.015);
	return (calc);
}
