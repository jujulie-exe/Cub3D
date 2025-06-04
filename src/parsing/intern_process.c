/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:56:45 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/01 13:11:02 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

char	*proccess_gnl(int fd)
{
	char	*tmp;
	char	*line;
	char	*ptr;

	line = ft_calloc(1, sizeof(char));
	tmp = NULL;
	while (line != NULL)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		ptr = line;
		line = ft_strjoin(line, tmp);
		free(ptr);
		free(tmp);
	}
	close(fd);
	return (line);
}

void	cleaning_maps(t_data_maps *ptr)
{
	size_t	len;
	char	*start_ptr;
	char	*clean_map;
	size_t	i;

	len = ft_strlen(ptr->map);
	start_ptr = ptr->map;
	clean_map = (char *)malloc(sizeof(char *) * (len + 1));
	if (!clean_map)
		return ;
	i = 0;
	while (*start_ptr)
	{
		if (*start_ptr == ' ' || *start_ptr == '	')
			clean_map[i] = '0';
		else
			clean_map[i] = *start_ptr;
		start_ptr++;
		i++;
	}
	clean_map[i] = '\0';
	free(ptr->map);
	ptr->map = clean_map;
}

bool	check_flags_maps(char *str)
{
	size_t	index;
	size_t	flags;

	index = 0;
	flags = 0;
	while (str[index])
	{
		if (valid_position(str[index]))
			flags++;
		index++;
	}
	if (flags == 1)
		return (true);
	return (false);
}

void	swap_and_split(t_data_maps *maps, char *line)
{
	char	**tmp_argv;
	size_t	i;

	i = 0;
	maps->argv = ft_split(line, DIV);
	free(line);
	while (maps->argv[i])
		i++;
	i--;
	maps->map = ft_strdup(maps->argv[i]);
	cleaning_maps(maps);
	free(maps->argv[i]);
	maps->argv[i] = NULL;
	if (maps->argv[0] == NULL)
		ft_free_all_and_exit(maps, "NO MAPSSS");
	tmp_argv = ft_split(maps->argv[0], '\n');
	free(maps->argv[0]);
	free(maps->argv);
	maps->argv = tmp_argv;
	if (check_flags_maps(maps->map) == false)
		ft_free_all_and_exit(maps, MSG_ERROR_FLAGS);
}
