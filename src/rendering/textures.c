/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/02 17:27:12 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

unsigned int my_color_get(t_wall *wall, int y, int x)
{
	int bpp = wall->bts / 8;
	char *pixel_ptr = wall->addr + (y * wall->szl + x * bpp);
	int	i = 0;
	unsigned int color = 0;
	 if (x < 0 || y < 0 || x >= wall->width || y >= wall->height)
        return (0);
	while (i < bpp)
	{
		color |= (unsigned char)pixel_ptr[i] << (8 * i);
		i++;
	}
	return (color);
}

void	init_texture(t_wall wall[], t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while(i < 3)
	{
		wall[i].index = i;
		wall[i].texture = mlx->texture[i];
		wall[i].width = mlx->txr_w[i];
		wall[i].height = mlx->txr_h[i];
		wall[i].addr = mlx_get_data_addr(mlx->texture[i], &wall[i].bts, &wall[i].szl, &wall[i].edn);
		i++;
	}
}

unsigned int	cmpt_tex(t_mlx *mlx, t_ray *ray, int y, int tex_index)
{
	double wall_x;
	if (ray->side == 0)
		 wall_x = mlx->player->posy + ray->dtw * ray->var_y;
	else
		wall_x = mlx->player->posx + ray->dtw * ray->var_x;
	wall_x = wall_x * 0.2;
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * (double)mlx->wall[tex_index].width);
	if ((ray->side == 0 && ray->var_x > 0) || (ray->side == 1 && ray->var_y < 0))
		tex_x = mlx->wall[tex_index].width - tex_x - 1;
	double step = (double)mlx->wall[tex_index].height / (double)ray->height;
	double tex_pos = (mlx->draw_start - mlx->height / 2 + ray->height / 2 ) * step;
	double current_pos = tex_pos + ( y - mlx->draw_start) * step;
	int tex_y = (int)current_pos;
	if (tex_y > 0)
		tex_y = tex_y % mlx->wall[tex_index].height;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= mlx->wall[tex_index].height)
		tex_y = mlx->wall[tex_index].height - 1;
	return ( my_color_get(&mlx->wall[tex_index], tex_x, tex_y));
}

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
