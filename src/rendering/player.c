/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:19:53 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/27 18:04:42 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	init_player(t_mlx *mlx)
{
	mlx->player->start_posx = mlx->p_x + 0.5;
	mlx->player->start_posy = mlx->p_y + 0.5;
	mlx->player->posx = mlx->player->start_posx;
	mlx->player->posy = mlx->player->start_posy;
	mlx->player->start_dir = mlx->valid_map[mlx->p_y][mlx->p_x];
	recup_start_dir(mlx->player);
	mlx->player->up = false;
	mlx->player->down = false;
	mlx->player->left = false;
	mlx->player->right = false;
	mlx->player->rot_left = false;
	mlx->player->rot_right = false;
}

void	recup_start_dir(t_player *player)
{
	if (player->start_dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->angle = 3 * PI / 2;
	}
	if (player->start_dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->angle = PI / 2;
	}
	if (player->start_dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->angle = 0;
	}
	else if (player->start_dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->angle = PI;
	}
}

int	key_press(int keycode, t_player *player)
{
	if (keycode == W)
		player->up = true;
	if (keycode == S)
		player->down = true;
	if (keycode == A)
		player->left = true;
	if (keycode == D)
		player->right = true;
	if (keycode == LE)
		player->rot_left = true;
	if (keycode == RI)
		player->rot_right = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->up = false;
	if (keycode == S)
		player->down = false;
	if (keycode == A)
		player->left = false;
	if (keycode == D)
		player->right = false;
	if (keycode == LE)
		player->rot_left = false;
	if (keycode == RI)
		player->rot_right = false;
	return (0);
}
