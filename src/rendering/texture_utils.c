/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:23:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 18:34:48 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"


unsigned int	median_color(t_wall *wall, int flags)
{
	t_median	md;

	md = (struct s_median) {0};
	while(md.x< flags / 50)
	{
		md.c = my_color_get(wall, md.x, 0);
		md.r = (md.c >> 16) & 0xFF;	
		md.g = (md.c >> 8) & 0xFF;	
		md.b = md.c & 0xFF;	
		md.sum_r += md.r;
		md.sum_g += md.g;
		md.sum_b += md.b;
		md.sum_t += md.c;
		md.x++;
	}
	md.avg_r = md.sum_r / md.x;
	md.avg_t = md.sum_t / md.x;
	md.avg_g = md.sum_g / md.x;
	md.avg_b = md.sum_b / md.x;
	return (md.avg_r << 16) | (md.avg_g << 8) | md.avg_b;
}

unsigned int	my_color_get(t_wall *wall, int y, int x)
{
	int				bpp;
	char			*pixel_ptr;
	int				i;
	unsigned int	color;

	bpp = wall->bts / 8;
	pixel_ptr = wall->addr + (y * wall->szl + x * bpp);
	i = 0;
	color = 0;
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
	while (i <= 3)
	{
		wall[i].index = i;
		wall[i].texture = mlx->texture[i];
		wall[i].width = mlx->txr_w[i];
		wall[i].height = mlx->txr_h[i];
		wall[i].addr = mlx_get_data_addr(mlx->texture[i],
				&wall[i].bts, &wall[i].szl, &wall[i].edn);
		i++;
	}
}

unsigned int	cmpt_tex(t_mlx *mlx, t_ray *ray, int y, int tex_index)
{
	t_tex	tex;
	
	tex = (struct s_tex){0};
	if (ray->side == 0)
		tex.wall_x = mlx->player->posy + ray->dtw * ray->var_y;
	else
		tex.wall_x = mlx->player->posx + ray->dtw * ray->var_x;
	tex.wall_x = tex.wall_x * 0.2;
	tex.wall_x -= floor(tex.wall_x);
	tex.tex_x = (int)(tex.wall_x * (double)mlx->wall[tex_index].width);
	if ((ray->side == 0 && cos(mlx->draw_start) > 0)
		|| (ray->side == 1 && sin(mlx->draw_start) < 0))
		tex.tex_x = mlx->wall[tex_index].width - tex.tex_x - 1;
	tex.step = (double)mlx->wall[tex_index].height / (double)ray->height;
	tex.tex_pos = (mlx->draw_start - mlx->height / 2 + ray->height / 2) * tex.step;
	tex.current_pos = tex.tex_pos + (y - mlx->draw_start) * tex.step;
	tex.tex_y = (int)tex.current_pos;
	if (tex.tex_y > 0)
		tex.tex_y = tex.tex_y % mlx->wall[tex_index].height;
	if (tex.tex_y < 0)
		tex.tex_y = 0;
	if (tex.tex_y >= mlx->wall[tex_index].height)
		tex.tex_y = mlx->wall[tex_index].height - 1;
	return (my_color_get(&mlx->wall[tex_index], tex.tex_x, tex.tex_y));
}
