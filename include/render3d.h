/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:35:33 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/10 14:09:57 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER3D_H
#define RENDER3D_H

#include "cube3d.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define W 13
#define S 1
#define A 0
#define D 2
#define LE 123
#define RI 124
#define ESC 53

#define BLOCKSIZE 5
#define PI 3.141592

typedef struct	s_ray
{
	int		pos_x_map; //starting position on the map
	int		pos_y_map;
	float	dir_x; //direction of the ray
	float	dir_y;
	float	dist_x; //dist to next point
	float	dist_y;
	float	delta_x; //dist for dda
	float	delta_y;
}	t_ray;

typedef struct	s_player
{
	float	x;
	float	y;
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	float	angle;
	bool	rot_left;
	bool	rot_right;
}	t_player;

#endif