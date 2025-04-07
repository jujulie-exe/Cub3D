/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:30 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/04 14:56:56 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int dda_calcul(float *dist_x, float *dist_y)
{
    
}

void    move_player(t_player *player)
{
    int speed;

    speed = ?;
    if (player->up)
        player->y += speed;
    if (player->down)
        player->y -= speed;
    if (player->left)
        player->x -= speed;
    if (player->right)
        player->x += speed;
}