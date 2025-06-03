/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 17:22:59 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

unsigned int	get_texture(t_mlx *mlx, t_ray *ray, t_wall *wall[], int y)
{
	int	color;

	if (ray->side == 0)
	{
		if (ray->var_x > 0)
			color = NO;
		else
			color = WE;
	}
	else
	{
		if (ray->var_y > 0)
			color = SO;
		else
			color = EA;
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

/*textures pour NSWE -> NO SO WE EA NE ???
mlx->textures contient les 4 ???*/