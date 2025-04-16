/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:30 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/16 16:54:04 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

int	collision(t_player *player, char **map)
{
	int	x;
	int	y;

	x = player->x / STEPSIZE;
	y = player->y / STEPSIZE;
	if (map[x][y] != 1)
		return (1);
	return (0);
}

void	move_player(t_player *player)
{
	int		speed;
	float	angle_speed;
	float	cos_a;
	float	sin_a;

	speed = 5;
	angle_speed = 10;
	cos_a = cos(player->angle);
	sin_a = sin(player->angle);
	if (player->rot_left)
		player->angle -= angle_speed;
	if (player->rot_right)
		player->angle += angle_speed;
	angle_protect(player->angle);
	if (player->up)
	{
		player->x += cos_a * speed;
		player->y += sin_a * speed;
	}
	if (player->down)
	{
		player->x -= cos_a * speed;
		player->y -= sin_a * speed;
	}
	if (player->left)
	{
		player->x += cos_a * speed;
		player->y -= sin_a * speed;
	}
	if (player->right)
	{
		player->x -= cos_a * speed;
		player->y += sin_a * speed;
	}
}

void	angle_protect(float *a)
{
	if (a > 2 * PI)
		a = 0;
	if (a < 0)
		a = 2 * PI;
}
