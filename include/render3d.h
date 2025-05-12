/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:35:33 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/12 17:50:19 by iwaslet          ###   ########.fr       */
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

# define STEPSIZE 5
# define PI 3.141592

// typedef struct s_ray
// {
// 	float	var_x; //dist for dda
// 	float	var_y;
// 	float	dtw;
// 	float	height;
// 	int		center_line;
// 	int		last_line;
// }	t_ray;

// typedef struct s_player
// {
// 	float	x;
// 	float	y;
// 	bool	up;
// 	bool	down;
// 	bool	left;
// 	bool	right;

// 	float	angle;
// 	bool	rot_left;
// 	bool	rot_right;
// }	t_player;

void	init_ray(t_ray *ray);
void	init_player(t_mlx *mlx);
int		draw_loop(t_mlx *mlx);
void	draw_line(t_mlx *mlx, float start_x, int i);
void	my_put_pixel(int x, int y, int color, t_mlx *mlx);

int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
void	move_player(t_player *player);
void	mov_adjustment(t_player *player, float cos, float sin);
void	angle_protect(float *a);

int		collision(t_ray *ray, t_player *player, char **map);
void	calc_dda(t_ray *ray, t_player *player, char **map);
float	calc_dist(float x, float y);
float	dist_to_wall(t_player *player, t_ray *ray);
void	calc_height(t_mlx *mlx, t_ray *ray, t_player *player);

#endif
