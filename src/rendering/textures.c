/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/04 17:25:58 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

unsigned int	get_texture(t_mlx *mlx, t_ray *ray, int y)
{
	int	color;

	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			color = EA;
		else
			color = WE;
	}
	else
	{
		if (ray->ray_dir_y < 0)
			color = SO;
		else
			color = NO;
	}
	return (cmpt_tex(mlx, ray, y, color));
}

void	draw_texture(t_mlx *mlx, t_ray *ray, int x, int y)
{
	int	color;

	color = 0;
	color = get_texture(mlx, ray, y);
	my_put_pixel(x, y, color, mlx);
}
