/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/03 17:27:15 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"
#include <sys/time.h>
#include <time.h>

double	time_to_double(struct timeval *t)
{
	return ((t->tv_sec + (t->tv_usec / 1000000.0)) * 1000.0);
}

double	time_diff(struct timeval *t1, struct timeval *t2, t_mlx *mlx)
{
	double	diff_ms;
	int		fps;
	char	*s;

	diff_ms = (time_to_double(t2) - time_to_double(t1));
	fps = 1000.0 / diff_ms;
	s = ft_itoa(fps);
	mlx_string_put(mlx->mlx, mlx->win, 1700, 30, 0xFFFFFF, s);
	free(s);
	return ((double)fps);
}

//gettimeofday(&t1, NULL);
//... do stuff ...
//gettimeofday(&t2, NULL);
//cout << "Time taken: " << time_diff(&t1, &t2) << "ms" << endl;

int	draw_loop(t_mlx *mlx)
{
	int				i;
	float			corr;
	float			start;
	struct timeval	tv1;
	struct timeval	tv2;

	i = 0;
	init_ray(mlx->ray);
	corr = (float)PI / 3 / mlx->width;
	start = mlx->player->angle - ((float)PI / 6);
	move_player(mlx->player, mlx);
	gettimeofday(&tv1, NULL);
	while (i < mlx->width)
	{
		draw_line(mlx, start, i);
		start += corr;
		i++;
	}
	gettimeofday(&tv2, NULL);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	time_diff(&tv1, &tv2, mlx);
	return (0);
}

void	draw_line(t_mlx *mlx, float start_x, int i)
{
	long int	y;

	y = 0;
	mlx->ray->var_x = mlx->player->posx;
	mlx->ray->var_y = mlx->player->posy;
	calc_dda(mlx->ray, mlx->player, mlx->valid_map, start_x);
	calc_height(mlx, mlx->ray, mlx->player);
	while (y < mlx->height / 2)
	{
		my_put_pixel(i, y, create_rgb(NULL, 'F'), mlx);
		y++;
	}
	while (y >= mlx->height / 2 && y < mlx->height)
	{
		my_put_pixel(i, y, create_rgb(NULL, 'C'), mlx);
		y++;
	}
	while (mlx->ray->center_line <= mlx->ray->last_line)
	{
		//my_put_pixel(i, mlx->ray->center_line, 0xB97AD1, mlx);
		mlx->draw_start = start_x;
		draw_texture(mlx, mlx->ray, i, mlx->ray->center_line);
		mlx->ray->center_line++;
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
