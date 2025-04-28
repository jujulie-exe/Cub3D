/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/28 16:22:17 by jfranco          ###   ########.fr       */
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
//	mlx->img = mlx_new_image(mlx->img, mlx->height, mlx->width);
//	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_pixel,
//			&mlx->line_len, &mlx->endian);
	corr = (float)PI / 3 / mlx->width;
	start = mlx->player->angle - ((float)PI / 6);
	move_player(mlx->player);
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
	(void)start_x;
	mlx->ray->var_x = mlx->player->x;
	mlx->ray->var_y = mlx->player->y;
	calc_dda(mlx->ray, mlx->player, mlx->valid_map);
	calc_height(mlx, mlx->ray, mlx->player);
	while (mlx->ray->center_line < mlx->ray->last_line)
	{
		my_put_pixel(i, mlx->ray->center_line, 0xFF0000, mlx);
		mlx->ray->center_line++;
	}
}

void	my_put_pixel(int x, int y, int color, t_mlx *mlx)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= mlx->width || y >= mlx->height)
		return ;
	pixel = (y * mlx->line_len) + (x * mlx->bits_pixel / 8) + mlx->addr;
	//mlx->(int)addr[pixel] = color;
	*(unsigned int *)pixel = color;
}
