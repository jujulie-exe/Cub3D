/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 18:19:16 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

unsigned int	get_texture(t_mlx *mlx, t_ray *ray, t_wall *wall[], int y, int x)
{
	int	color;

	if (ray->side == 0)
	{
		if (cos(mlx->draw_start) > 0)
			color = EA;
		else
			color = WE;
	}
	else
	{
		if (sin(mlx->draw_start) < 0)
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
	color = get_texture(mlx, ray, &mlx->wall, y);
	my_put_pixel(x, y, color, mlx);
}

// int	get_texture(t_mlx *mlx, t_ray *ray, t_wall *wall, float start)
// {
// 	int	color;

// 	if (ray->side == 0)
// 	{
// 		if (cos(start) > 0)
// 		{
// 			wall->index = 3;
// 			color = 0x800000;
// 		}
// 		else if (cos(start) <= 0)
// 		{
// 			wall->index = 2;
// 			color = 0xFA8072;
// 		}
// 	}
// 	else
// 	{
// 		if (sin(start) < 0)
// 		{
// 			wall->index = 0;
// 			color = 0xFFD700;
// 		}
// 		else if (sin(start) >= 0)
// 		{
// 			wall->index = 1;
// 			color = 0x9ACD32;
// 		}
// 	}
// 	return (color);
//}
