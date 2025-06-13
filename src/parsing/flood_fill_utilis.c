/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:40:26 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/13 17:01:23 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

bool	check_div(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == DIV)
		{
			free(line);
			line = NULL;
			return (true);
		}
		i++;
	}
	return (false);
}

static size_t	max_lenth(char **maps)
{
	size_t	lenght;
	size_t	max_lengh;
	size_t	y;

	lenght = 0;
	max_lengh = 0;
	y = 0;
	while (maps[y] != NULL)
	{
		lenght = ft_strlen(maps[y]);
		if (lenght > max_lengh)
			max_lengh = lenght;
		y++;
	}
	return (max_lengh);
}

static char	*ft_straddzero(const char *s1, size_t max)
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
	size_t	malloc_y;
	size_t	malloc_x;
	char	**tmp;

	malloc_y = 0;
	tmp = data->copy_maps;
	while (maps[malloc_y] != NULL)
		malloc_y++;
	data->copy_maps = malloc(sizeof(char *) * (malloc_y + 1));
	malloc_x = max_lenth(maps);
	malloc_y = 0;
	while (maps[malloc_y] != NULL)
	{
		data->copy_maps[malloc_y] = ft_straddzero(maps[malloc_y], malloc_x);
		malloc_y++;
	}
	data->copy_maps[malloc_y] = NULL;
	free_double_array(&tmp);
}

void	remplace(t_fill *data, char search, char rmplc)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	while (data->copy_maps[y])
	{
		x = 0;
		while (data->copy_maps[y][x])
		{
			if (data->copy_maps[y][x] == search)
				data->copy_maps[y][x] = rmplc;
			x++;
		}
		y++;
	}
}
