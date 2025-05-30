/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/30 12:03:24 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	init_texture(t_wall *wall)
{
	wall->index = 0;
}

int	get_texture(t_mlx *mlx, t_ray *ray, t_wall *wall)
{
	int	color;
	
	if (ray->side == 0)
	{
		if (ray->var_x > 0 && mlx->player->angle < PI / 4 && mlx->player->angle > 7 * PI / 4)
		{
			wall->index = 3;
			color = 0x800000;
		}
		else
		{
			wall->index = 2;
			color = 0xFA8072;
		}
	}
	else
	{
		if (ray->var_y < 0) // && mlx->player->angle < PI && mlx->player->angle > 0)
		{
			wall->index = 0;
			color = 0xFFD700;
		}
		else
		{
			wall->index = 1;
			color = 0x9ACD32;
		}
	}
	return (color);
}

// void	draw_texture(t_mlx *mlx, t_ray *ray)
// {
// 	int	y;
	
// 	y = 0;
// }

void	update_pixels(t_mlx *mlx, t_ray *ray, int x, int y)
{
	int	color;

	init_texture(mlx->wall);
	color = get_texture(mlx, ray, mlx->wall);
	my_put_pixel(x, y, color, mlx);
}

/*textures pour NSWE -> NO SO WE EA NE ???
mlx->textures contient les 4 ???*/