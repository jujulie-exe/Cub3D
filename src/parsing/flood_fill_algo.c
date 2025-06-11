/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:47:10 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/10 19:56:03 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*  ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( */

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
			{
				 data->c = data->copy_maps[data->y][data->x]; 
				return ;
			}
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
	if (data->copy_maps[y][x] != data->target
		&& !valid_position(data->copy_maps[y][x]))
		return ;
	data->copy_maps[y][x] = data->color;
	flood_fill_algo(data, y - 1, x);
	flood_fill_algo(data, y, x - 1);
	flood_fill_algo(data, y + 1, x);
	flood_fill_algo(data, y, x + 1);
}

void	posiztion_player(size_t *x, size_t *y, t_fill *data)
{
	(*x) = data->x;
	(*y) = data->y;
}

size_t	max_lenth(char **maps)
{
	size_t	lenght = 0;
	size_t	max_lengh = 0;
	size_t	y = 0;
	while(maps[y] != NULL)
	{
		lenght = ft_strlen(maps[y]);
		if (lenght > max_lengh)
			max_lengh = lenght;
		y++;
	}
	return (max_lengh);
}

char	*ft_straddzero(const char *s1, size_t max)
{
	size_t		i;
	char		*s2;

	i = 0;
	s2 = (char *)malloc((max + 1) * (sizeof(char)));
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	while (i < max)
	{
		s2[i] = '0';
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	proccess_copy_maps(char **maps, t_fill *data)
{
	size_t	malloc_y = 0;
	size_t	malloc_x = 0;
	char	**tmp = data->copy_maps;
	while(maps[malloc_y] != NULL)
		malloc_y++;
	data->copy_maps = malloc(sizeof(char *) * (malloc_y + 1));
	malloc_x = max_lenth(maps);
	malloc_y = 0;
	while(maps[malloc_y] != NULL)
	{
		data->copy_maps[malloc_y] = ft_straddzero(maps[malloc_y], malloc_x);
		malloc_y++;
	}
	data->copy_maps[malloc_y] = NULL;
	free_double_array(&tmp);
}

void	print_maps(char **maps)
{
	size_t	y = 0;
	while (maps[y] != NULL)
	{
		printf("%s\n", maps[y]);
		y++;
	}
}

void	fill_flod(t_data_maps *ptr)
{
	t_fill	data;

	data.copy_maps = ft_split(ptr->map, '\n');
	proccess_copy_maps(data.copy_maps, &data);
	search_player(&data);
	posiztion_player(&ptr->ptr_mlx->p_x, &ptr->ptr_mlx->p_y, &data);
	data.target = '0';
	data.color = 'C';
	flood_fill_algo(&data, data.y, data.x);
	print_maps(data.copy_maps);
	if (!control_fill_map(&data))
	{
		free_double_array(&data.copy_maps);
		ft_free_all_and_exit(ptr, MSG_ERROR_MAP);
	}
	size_t	x;
	size_t	y = 0;
	while (data.copy_maps[y])
	{
		x = 0;
		while(data.copy_maps[y][x])
		{
			if (data.copy_maps[y][x] == '0')
				data.copy_maps[y][x] = '1';
			x++;
		}
		y++;
	}
	data.target = 'C';
	data.color = '0';
	flood_fill_algo(&data, data.y, data.x);
	data.copy_maps[data.y][data.x] = data.c;
	ptr->ptr_mlx->valid_map = NULL;
	ptr->ptr_mlx->valid_map = data.copy_maps;
	print_maps(ptr->ptr_mlx->valid_map);
}
