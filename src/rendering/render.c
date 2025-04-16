/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/16 17:03:05 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
//fcts dont j'ai besoin pour le render, pas a implementer tel quel
int	render_game(t_mlx game)
{
	init_player(&game);
	init_ray(&game);
	draw_loop(game);
}

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
	while (calc_height(mlx, mlx->ray, mlx->player))
}

//while (ray->closest_line < ray->last_line)
//{put_pixel(dessiner le mur) ; ray->closest_line++}

// void	draw_map(char **valid_map)
// {
// 	int	i;
// 	int	j;
// 	int	color;

// 	i = 0;
// 	j = 0;
// 	color = 0x00FF00;
// 	while (valid_map[i++])
// 	{
// 		while (valid_map[i][j++])
// 		{
// 			if (valid_map[i][j] == 1)
// 				draw_line();//draw wall
// 		}
// 	}
// }

void	my_put_pixel(int x, int y, int color, t_mlx *mlx);
{
	unsigned int	pixel;

	if (x < 0 || y < 0 || x >= mlx->width || y >= mlx->height)
		return ;
	pixel = (y * mlx->line_len) + (x * mlx->bits_pixel / 8);
	mlx->addr[pixel] = color;
}
