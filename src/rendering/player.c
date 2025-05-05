/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:19:53 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/21 18:20:56 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void	find_start_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->valid_map[y++])
	{
		while (mlx->valid_map[y][x++])
		{
			if (valid_map[y][x] == NSWE ?)
			{
				mlx->player->start_dir = valid_map[y][x];
				mlx->player->posx = x + 0.5;
				mlx->player->posy = y + 0.5;
			}
		}
	}
}

void	init_player(t_mlx *mlx)
{
	
	find_start_pos(mlx);
	mlx->player->angle = PI / 2;
	mlx->player->up = false;
	mlx->player->down = false;
	mlx->player->left = false;
	mlx->player->right = false;
	mlx->player->rot_left = false;
	mlx->player->rot_right = false;
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
