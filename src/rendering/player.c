/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:19:53 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/21 17:09:20 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

void	init_player(t_mlx *mlx)
{
	mlx->player->x = mlx->width / 2;
	mlx->player->y = mlx->height / 2;
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
