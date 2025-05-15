/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:33:05 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/15 17:23:12 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	init_ray(t_ray *ray)
{
	ray->var_x = 0;
	ray->var_y = 0;
	ray->dtw = 0;
	ray->height = 0;
	ray->center_line = 0;
	ray->last_line = 0;
}

int	collision(t_ray *ray, t_player *player, char **map)
{
	int	x;
	int	y;
	(void)player;
	x = (int)(ray->var_x);
	y = (int)(ray->var_y);
	//printf("%i, %i\n", x, y);
	if (map[y][x] != '1')
		return (0);
	return (1);
}
