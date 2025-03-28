/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:34 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/28 16:40:42 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int	check_valid_name(char *name)
{
	char	*ptr;

	ptr = ft_strrchr(name, '.');
	if (ptr)
	{
		if (!ft_strncmp(ptr + 1, "cub", 4))
			return (0);
		else
		return (ft_fprintf(2, "%s", MSG_ERROR_CUB), -1);
	}
	else
		return (ft_fprintf(2, "%s", MSG_ERROR_EXT), -1);
}

int	ptr_color(t_data_maps *maps)
{
	char *srr[] = { "C ", "F ", "C	", "F	", NULL};
	size_t	i;
	size_t	y;

	i = 0;
	while (maps->argv[i])
	{
		y = 0;
		while (srr[y])
		{
			if (!ft_strncmp(maps->argv[i], srr[y], 2))
			{
				if (y == 0 || y == 2)
					maps->up_color = maps->argv[i];
				if (y == 1 || y == 3)
					maps->down_color = maps->argv[i];
			}
			y++;
		}
		i++;
	}
	return (0);
}

void	ptr_texture(t_data_maps *maps)
{
	char *srr[] = {"NE ", "WE ", "NO ", "SO ", "NE	", "WE	", "NO	", "SO	", NULL};
	size_t	i;
	size_t	y;

	i = 0;
	while (maps->argv[i] != NULL)
	{
		y = 0;
		while (srr[y] != NULL)
		{
			if (!ft_strncmp(maps->argv[i], srr[y], 3))
			{
				if (y == 0 || y == 4)
					maps->path_ne = maps->argv[i];
				else if (y == 1 || y == 5)
					maps->path_we = maps->argv[i];
				else if (y == 2 || y == 6)
					maps->path_no = maps->argv[i];
				else if (y == 3 || y == 7)
					maps->path_so = maps->argv[i];
			}
			y++;
		}
		i++;
	}
}

int is_valid_map_char(char c)
{
    return (c == '0' || c == '1' || c == '2' || 
            c == 'N' || c == 'S' || c == 'E' || c == 'W' || 
            c == ' ' || c == '\n' || c == '	');
}

int	serch_map_and_validate(char *str)
{
	size_t	i;
	bool	valid;
	size_t	index_maps;

	i = 0;
	valid = false;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			index_maps = i + 1;
			valid = true;
			while (str[index_maps])
			{
				if(!is_valid_map_char(str[index_maps]))
				{
					valid = false;
					break ;
				}
				index_maps++;
			}
		}
		if (valid == true)
			break ;
		i++;
	}
	if (valid == true)
		return (str[i] = DIV, 1);
	return (0);
}


int	proccesing_file_cub(t_data_maps *maps)
{
	char	*line = NULL;
	int	fd;
	
	if (check_valid_name(maps->name_maps))
		exit(-1);
	fd = open(maps->name_maps, O_RDONLY);
	if (fd < 0)
		ft_free_all_and_exit(NULL, MSG_ERROR_FILE);
	line = proccess_gnl(fd);
	if (serch_map_and_validate(line) == 0)
		ft_free_all_and_exit(NULL, "NO VALID MAP");
	swap_and_split(maps, line);
	if (maps->argv == NULL)
		ft_free_all_and_exit(NULL, "NO VALID ARG");
	trim(maps);
	ptr_texture(maps);
	ptr_color(maps);
	validazione(maps);
	return(0);
}
