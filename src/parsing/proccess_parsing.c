/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccess_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:34 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/27 17:01:18 by jfranco          ###   ########.fr       */
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
		return (ft_fprintf(2,"%s", "Error\n is not .cub extession\n"), -1);
	}
	else
		return (ft_fprintf(2,"%s", "Error\n Add type valid type exetssion\n Valid estession is .cub\n"), -1);
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
		return (str[i] = '#', 1);
	return (0);
}

void	cleaning_arg(t_data_maps *ptr)
{
	size_t	i;
	size_t	y;
	size_t	count;

	i = 0;
	y = 0;
	count = 0;
	if (ptr->argv)
	{
		while (ptr->argv[i])
		{
			if(ft_strlen(ptr->argv[i]) > 0)
				count++;
			i++;
		}

	}
	char **new_argv = malloc(sizeof(char **) * count + 1);
	i = 0;
	while (ptr->argv[i])
	{
		if(ft_strlen(ptr->argv[i]) > 0)
		{
			new_argv[y] = ft_strdup(ptr->argv[i]);
			y++;
		}
		i++;

	}
	new_argv[y] = NULL;
	ft_clean_argv(ptr);
	ptr->argv = new_argv;
}

void	trim(t_data_maps *ptr)
{
	size_t	i = 0;
	if (ptr->argv)
	{
		while (ptr->argv[i])
		{
			char *trim = ft_strtrim(ptr->argv[i], " 	");
			free(ptr->argv[i]);
			ptr->argv[i] = NULL;
			ptr->argv[i] = trim;
			i++;
		}
	}
	cleaning_arg(ptr);
}
int	proccesing_file_cub(t_data_maps *maps)
{
	char	*line = NULL;
	char	*tmp = NULL;
	int	fd;
	
	if (check_valid_name(maps->name_maps))
		exit(-1);
	fd = open(maps->name_maps, O_RDONLY);
	if (fd < 0)
		ft_free_all_and_exit(NULL, "FILE DON'EXTIST");
	//tmp = ft_calloc(sizeof(char *), 1);
	line = ft_calloc(1, sizeof(char));
	while(line != NULL)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		char *ptr = line;
		line = ft_strjoin(line, tmp);
		free(ptr);
		free(tmp);
	}
	// cerco la mapp
	if (serch_map_and_validate(line) == 0)
		exit(1);
	maps->argv = ft_split(line, '#');
	maps->map = ft_strdup(maps->argv[1]);
	free(maps->argv[1]);
	maps->argv[1] = NULL;
	char **tmp_argv = ft_split(maps->argv[0], '\n');
	free(maps->argv[0]);
	free(maps->argv);
	maps->argv = tmp_argv;
	free(line);
//qui dovrei trimmare piccolo ciclo while e via
	if (maps->argv == NULL)
		return (-1);
	trim(maps);
	ptr_texture(maps);
	ptr_color(maps);
	validazione(maps);
	return(0);
}
