/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:47:10 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/04 13:08:16 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ */

#include "../../include/cube3d.h"

void	search_player(t_fill *data)
{
	data->y = 0;
	while (data->copy_maps[data->y])
	{
		data->x = 0;
		while (data->copy_maps[data->y][data->x] != '\0')
		{
			if (valid_position(data->copy_maps[data->y][data->x]))
					return ;
			data->x++;
		}
		data->y++;
	}

}
void	flood_fill_algo(t_fill *data, ssize_t y, ssize_t x)
{
	if (y < 0 || !data->copy_maps[y])
		return ;
	if (x < 0 || x > (int long)ft_strlen(data->copy_maps[y]))
		return ;
	if (data->copy_maps[y][x] != data->target && !valid_position(data->copy_maps[y][x]))
		return ;
	data->copy_maps[y][x] = data->color;
	flood_fill_algo(data, y - 1, x);
	flood_fill_algo(data, y, x - 1);
	flood_fill_algo(data, y + 1, x);
	flood_fill_algo(data, y, x + 1);

}
int	ft_confront(t_fill *data, size_t index)
{
	size_t len1 = ft_strlen(data->copy_maps[index]);
	size_t len2 = ft_strlen(data->copy_maps[index - 1]);
	if (len1 > len2)
		while (len1 != len2)
			len1--;
	else if (len1 < len2)
	{
		len1 = (len2 - len1) - 1;
		index = index - 1;
	}
	if (data->copy_maps[index][len1] == data->color)
		return (1);
	return (0);
}
bool	control_fill_map(t_fill *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (data->copy_maps[0][x])
	{
		if (data->copy_maps[0][x] == data->color)
			return (false);
		x++;
	}
	while (data->copy_maps[y])
	{
		if (data->copy_maps[y][0] == data->color || data->copy_maps[y][ft_strlen(data->copy_maps[y])] == data->color)
			return (false);
		if (y > 0 && (ft_strlen(data->copy_maps[y]) != ft_strlen(data->copy_maps[y - 1])))
			if (ft_confront(data, y) == 1)
				return (false);
		y++;
	}
	x = 0;
	y--;
	while (data->copy_maps[y][x])
	{
		if (data->copy_maps[y][x] == data->color)
			return (false);
		x++;
	}
	return (true);
}

void	posiztion_player(size_t *x, size_t *y, t_fill *data)
{
	(*x) = data->x;
	(*y) = data->y;
}
void	fill_flod(t_data_maps *ptr)
{
	t_fill	data;

	data.copy_maps = ft_split(ptr->map, '\n');
	search_player(&data);
	posiztion_player(&ptr->ptr_mlx->p_x, &ptr->ptr_mlx->p_y, &data);
	data.target = '0';
	data.color = 'C';
	flood_fill_algo(&data, data.y, data.x);
	if (!control_fill_map(&data))
	{
		free_double_array(&data.copy_maps);
		ft_free_all_and_exit(ptr, MSG_ERROR_MAP);
	}
	free_double_array(&data.copy_maps);
	ptr->ptr_mlx->valid_map = NULL;
	ptr->ptr_mlx->valid_map = ft_split(ptr->map, '\n');
}

