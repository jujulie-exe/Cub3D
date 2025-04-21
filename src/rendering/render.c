/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/21 18:04:31 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

int	draw_loop(t_mlx *mlx)
{
	int		i;
	float	corr;
	float	start;

	i = 0;
	corr = PI / 3 / mlx->width;
	start = player->angle - (PI / 6);
	move_player(mlx->player);
	while (i < mlx->width)
	{
		draw_line(mlx, start, i);
		start += corr;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	retrun (0);
}

void	draw_line(t_mlx *mlx, float start_x, int i)
{
	mlx->ray->var_x = mlx->player->x;
	mlx->ray->var_y = mlx->player->y;
	calc_dda(&mlx->ray, mlx->player, mlx->valid_map);
	calc_height(mlx, mlx->ray, mlx->player);
	while (ray->center_line < ray->last_line)
	{
		my_put_pixel(i, ray->center_line, 0x0000FF, mlx);
		ray->center_line++;
	}
}

void	my_put_pixel(int x, int y, int color, t_mlx *mlx)
{
	unsigned int	pixel;

	if (x < 0 || y < 0 || x >= mlx->width || y >= mlx->height)
		return ;
	pixel = (y * mlx->line_len) + (x * mlx->bits_pixel / 8);
	mlx->addr[pixel] = color;
}
