/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/11 19:39:34 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"

int	render_game(t_mlx game)
{
	init_player(&game->player);
	init_ray(&game->ray);
}

void	draw_map(char **valid_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (valid_map[i++])
	{
		while (valid_map[i][j++])
		{
			if (valid_map[i][j] == 1)
				draw_line();//draw wall
		}
	}
}

void	my_put_pixel();