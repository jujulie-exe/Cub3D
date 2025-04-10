/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:37:17 by iwaslet           #+#    #+#             */
/*   Updated: 2025/04/10 14:01:14 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	calc_dda(t_ray *ray, t_player *player, char **map)
{
	while (!collision(ray, player, map))
	{
		ray->delta_x += cos(player->angle);
		ray->delta_y += sin(player->angle);
	}
}
