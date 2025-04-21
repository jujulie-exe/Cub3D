/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:33:05 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/21 16:57:50 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

t_ray	init_ray(t_mlx *mlx)
{
	mlx->ray->var_x = 0;
	mlx->ray->var_x = 0;
	mlx->ray->dtw = 0;
	mlx->ray->height = 0;
	mlx->ray->center_wall = 0;
	mlx->ray->last_line = 0;
}

int	collision(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x / STEPSIZE;
	y = player->y / STEPSIZE;
	if (map[x][y] != 1)
		return (1);
	return (0);
}
