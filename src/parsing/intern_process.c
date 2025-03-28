/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:56:45 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/28 16:42:28 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

char	*proccess_gnl(int fd)
{
	char	*tmp;
	char	*line;
	line = ft_calloc(1, sizeof(char));

	tmp = NULL;
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
	return (line);
}
// #
void	cleaning_maps(t_data_maps *ptr)
{
	size_t	len;
	char	*start_ptr;
	char	*clean_map;
	size_t	i;

	len = ft_strlen(ptr->map);
	start_ptr = ptr->map;
	clean_map =(char *)malloc(sizeof(char *) * (len + 1));
	if (!clean_map )
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
	printf("[cleaning maps] %s", clean_map);
	free(ptr->map);
	ptr->map = clean_map;
}

void	swap_and_split(t_data_maps *maps, char *line)
{
	char	**tmp_argv;
	size_t	i;

	i = 0;
	maps->argv = ft_split(line, DIV);
	while (maps->argv[i])
		i++;
	i--;
	maps->map = ft_strdup(maps->argv[i]);
	printf("%s", maps->map);
	cleaning_maps(maps);
	free(maps->argv[i]);
	maps->argv[i] = NULL;
	tmp_argv = ft_split(maps->argv[0], '\n');
	free(maps->argv[0]);
	free(maps->argv);
	maps->argv = tmp_argv;
	free(line);
}
