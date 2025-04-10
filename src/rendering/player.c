/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:19:53 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/10 13:59:08 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

void	init_player(t_player *player)
{
	player->x = window_W / 2; //mettre les vraies variables par rapport à la fenetre
	player->y = window_H / 2;
	player->angle = PI / 2;
	player->up = false; //voir comment on fait pour les keyhooks
	player->down = false;
	player->left = false;
	player->right = false;
	player->rot_left = false;
	player->rot_right = false;
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
	if (keycode == L)
		player->rot_left = true;
	if (keycode == R)
		player->rot_right = true;
	return (0);
}
