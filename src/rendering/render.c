/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/27 18:34:23 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

int	draw_loop(t_mlx *mlx)
{
	int		i;
	float	corr;
	float	start;

	i = 0;
	init_ray(mlx->ray);
	corr = (float)PI / 3 / mlx->width;
	start = mlx->player->angle - ((float)PI / 6);
	move_player(mlx->player, mlx); //recalculer l'img qu'en cas de mov
	while (i < mlx->width)
	{
		draw_line(mlx, start, i);
		start += corr;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	draw_line(t_mlx *mlx, float start_x, int i)
{
	int	y;

	y = 0;
	mlx->ray->var_x = mlx->player->posx;
	mlx->ray->var_y = mlx->player->posy;
	calc_dda(mlx->ray, mlx->player, mlx->valid_map, start_x);
	calc_height(mlx, mlx->ray, mlx->player, start_x);
	while (y < mlx->height / 2)
	{
		my_put_pixel(i, y, create_rgb(NULL, 'F'), mlx);
		y++;
	}
	while (y >= mlx->height / 2 && y <= mlx->height) //enlever le 2e = ?
	{
		my_put_pixel(i, y, create_rgb(NULL, 'C'), mlx);
		y++;
	}
	while (mlx->ray->center_line <= mlx->ray->last_line)
	{
		//draw_texture(mlx);
		my_put_pixel(i, mlx->ray->center_line, 0xB97AD1, mlx);
		mlx->ray->center_line++;
		//update_pixels(mlx, mlx->ray);
	}
}

void	my_put_pixel(int x, int y, int color, t_mlx *mlx)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= mlx->width || y >= mlx->height)
		return ;
	pixel = (y * mlx->line_len) + (x * mlx->bits_pixel / 8) + mlx->addr;
	*(unsigned int *)pixel = color;
}
/* mlx_xpm_file_to_image(m->win.mlx_ptr, m->el.w_path,
		&m->tex.texwidth, &m->tex.texheight))
	mlx_get_data_addr(m->tex.color_w,
		&m->img.bits_per_pixel, &m->img.line_length, &m->img.endian);*/