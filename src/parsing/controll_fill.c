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
/*  ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( */

#include "../../include/cube3d.h"

int	ft_confront(t_fill *data, size_t index)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(data->copy_maps[index]);
	len2 = ft_strlen(data->copy_maps[index - 1]);
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

bool	control_up_border(t_fill *data, size_t *x)
{
	while (data->copy_maps[0][(*x)])
	{
		if (data->copy_maps[0][(*x)] == data->color)
			return (false);
		(*x)++;
	}
	return (true);
}

bool	control_down_border(t_fill *data, size_t *y, size_t *x)
{
	while (data->copy_maps[(*y)][(*x)])
	{
		if (data->copy_maps[(*y)][(*x)] == data->color)
			return (false);
		(*x)++;
	}
	return (true);
}

bool	control_fill_map(t_fill *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	if (control_up_border(data, &x) == false)
		return (false);
	while (data->copy_maps[y])
	{
		if (data->copy_maps[y][0] == data->color
			|| data->copy_maps[y][ft_strlen(data->copy_maps[y])] == data->color)
			return (false);
		if (y > 0 && (ft_strlen(data->copy_maps[y])
				!= ft_strlen(data->copy_maps[y - 1])))
			if (ft_confront(data, y) == 1)
				return (false);
		y++;
	}
	x = 0;
	y--;
	if (control_down_border(data, &y, &x) == false)
		return (false);
	return (true);
}
