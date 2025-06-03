/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 17:38:16 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

unsigned int	get_texture(t_mlx *mlx, t_ray *ray, t_wall *wall[], int y, int x)
{
	int	color;
	
	if (ray->side == 0)
	{
		if (ray->var_x > 0 && mlx->player->angle < PI / 4 || mlx->player->angle > 7 * PI / 4)
			color = NO;
		else
			color = WE;
	}
	else if (ray->side == 1)
	{
		if (ray->var_y > 0) // && mlx->player->angle < PI && mlx->player->angle > 0)
			color = SO;
		else
			color = EA;
	}
	return (cmpt_tex(mlx, ray, y, color));
}


void	update_pixels(t_mlx *mlx, t_ray *ray, int x, int y)
{
	int	color;
	color = get_texture(mlx, ray, &mlx->wall, y, x);
	my_put_pixel(x, y, color, mlx);
}

/*textures pour NSWE -> NO SO WE EA NE ???
mlx->textures contient les 4 ???*/
