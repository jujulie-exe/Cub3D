/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:30 by iwaslet           #+#    #+#             */
/*   Updated: 2025/06/04 19:04:35 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	move_player(t_player *player, t_mlx *mlx)
{
	rot_adjustment(player, mlx);
	angle_protect(&player->angle);
	if (player->up)
		mov_adjustment(player, player->dirx, player->diry, mlx);
	if (player->down)
		mov_adjustment(player, -player->dirx, -player->diry, mlx);
	if (player->left)
		mov_adjustment(player, player->diry, -player->dirx, mlx);
	if (player->right)
		mov_adjustment(player, -player->diry, player->dirx, mlx);
}

void	mov_adjustment(t_player *player, float cos, float sin, t_mlx *mlx)
{
	float		speed;

	speed = 0.4;
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
	if (mlx->valid_map[(int)player->posy][(int)player->posx] != '1')
	{
		if (player->rot_right)
			add_rot(player, angle_speed, RIGHT);
		if (player->rot_left)
			add_rot(player, -angle_speed, LEFT);
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
