/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:30 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/08 14:23:55 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

int	dda_calcul(float *dist_x, float *dist_y)
{

}

void	move_player(t_player *player)
{
	int speed;
	float	angle_speed;
	float	cos_a;
	float	sin_a;

	speed = ?;
	angle_speed = ?;
	cos_a = cos(player->angle);
	sin_a = sin(player->angle);

	if (player->rot_left)
		player->angle -= angle_speed;
	if (player->rot_right)
		player->angle += angle_speed;
	angle_protect(player->angle);
	if (player->up)
		player->y += speed;
	if (player->down)
		player->y -= speed;
	if (player->left)
		player->x -= speed;
	if (player->right)
		player->x += speed;
}

void	angle_protect(float *a)
{
	if (a > 2 * PI)
		a = 0;
	if (a < 0)
		a = 2 * PI;
}