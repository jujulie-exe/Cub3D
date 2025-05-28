/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/28 15:53:06 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	init_texture(t_texture *texture)
{
	texture->index = 0;
}

void	get_texture(t_mlx *mlx, t_ray *ray, t_texture *texture)
{
	if (ray->side == 0)
	{
		if (ray->var_x > 0)
			texture->index = 3;
		else
			texture->index = 2;
	}
	else
	{
		if (ray->var_y > 0)
			texture->index = 0;
		else
			texture->index = 1;
	}
}

void	draw_texture(t_mlx *mlx, t_ray *ray)
{
	int	y;
}

void	update_pixels(t_mlx *mlx, t_ray *ray)
{
	int	color;

	init_texture(mlx->textstruct);
	get_texture(mlx, ray, textstruct);
}

/*textures pour NSWE -> NO SO WE EA NE ???
mlx->textures contient les 4 ???*/