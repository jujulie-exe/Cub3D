/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:30 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/30 18:48:24 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	move_player(t_player *player, t_mlx *mlx)
{
	float	cos_a;
	float	sin_a;

	cos_a = cos(player->angle);
	sin_a = sin(player->angle);
	rot_adjustment(player, mlx);
	angle_protect(&player->angle);
	if (player->up)
		mov_adjustment(player, cos_a, sin_a, mlx);
	if (player->down)
		mov_adjustment(player, -cos_a, -sin_a, mlx);
	if (player->left)
		mov_adjustment(player, sin_a, -cos_a, mlx);
	if (player->right)
		mov_adjustment(player, -sin_a, cos_a, mlx);
}

void	mov_adjustment(t_player *player, float cos, float sin, t_mlx *mlx)
{
	float		speed;

	speed = 0.5;
	player->posx += cos * speed;
	player->posy += sin * speed;
	if (mlx->valid_map[(int)player->posy][(int)player->posx] == '1')
	{
		player->posx -= cos * speed;
		player->posy -= sin * speed;
	}
	move_release(player);
}

void	rot_adjustment(t_player *player, t_mlx *mlx)
{
	float	angle_speed;

	angle_speed = 0.1;
	if (player->rot_left)
		player->angle -= angle_speed;
	if (player->rot_right)
		player->angle += angle_speed;
	if (mlx->valid_map[(int)player->posy][(int)player->posx] == '1')
	{
		if (player->rot_left)
			player->angle += angle_speed;
		if (player->rot_right)
			player->angle -= angle_speed;
	}
	rot_release(player);
}

void	move_release(t_player *player)
{
	if (player->up)
		player->up = false;
	if (player->down)
		player->down = false;
	if (player->left)
		player->left = false;
	if (player->right)
		player->right = false;
}

void	rot_release(t_player *player)
{
	if (player->rot_left)
		player->rot_left = false;
	if (player->rot_right)
		player->rot_right = false;
}
