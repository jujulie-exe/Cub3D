/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:30 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/21 17:17:55 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

void	move_player(t_player *player)
{
	float	angle_speed;
	float	cos_a;
	float	sin_a;

	angle_speed = 10;
	cos_a = cos(player->angle);
	sin_a = sin(player->angle);
	if (player->rot_left)
		player->angle -= angle_speed;
	if (player->rot_right)
		player->angle += angle_speed;
	angle_protect(player->angle);
	if (player->up)
		mov_adjustment(player, cos_a, sin_a);
	if (player->down)
		mov_adjustment(player, -cos_a, -sin_a);
	if (player->left)
		mov_adjustment(player, cos_a, -sin_a);
	if (player->right)
		mov_adjustment(player, -cos_a, sin_a);
}

void	mov_adjustment(t_player *player, float cos, float sin)
{
	int		speed;

	speed = 5;
	player->x += cos * speed;
	player->y += sin * speed;
}

void	angle_protect(float *a)
{
	if (a > 2 * PI)
		a = 0;
	if (a < 0)
		a = 2 * PI;
}

/*void	move_player(t_player *player)
{
	float	angle_speed;
	float	cos_a;
	float	sin_a;

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
}*/