/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:35:33 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/27 18:20:27 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER3D_H
# define RENDER3D_H

# include "cube3d.h"
# include <stdio.h>
# include <math.h>
# include <stdbool.h>

# define W 13
# define S 1
# define A 0
# define D 2
# define LE 123
# define RI 124
# define ESC 53

# define STEPSIZE 1.5
# define PI 3.1415926535

void	init_ray(t_ray *ray);
void	init_player(t_mlx *mlx);
int		draw_loop(t_mlx *mlx);
void	draw_line(t_mlx *mlx, float start_x, int i);
void	my_put_pixel(int x, int y, int color, t_mlx *mlx);

int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player, t_mlx *mlx);
void	mov_adjustment(t_player *player, float cos, float sin, t_mlx *mlx);
void	move_release(t_player *player);
void	rot_release(t_player *player);
void	angle_protect(float *a);
void	recup_start_dir(t_player *player);

int		collision(t_ray *ray, t_player *player, char **map);
void	calc_dda(t_ray *ray, t_player *player, char **map, float start);
float	calc_dist(float x, float y);
void	angle_calcul(t_player *player, t_ray *ray, float dx, float dy);
void	projection(t_player *player, t_ray *ray);
float	dist_to_wall(t_player *player, t_ray *ray, float start);
void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player, float start);

#endif
