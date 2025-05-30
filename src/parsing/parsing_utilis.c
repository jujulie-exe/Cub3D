/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:15:22 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/27 14:32:21 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

size_t	count_index_empty(char **argv)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			if (ft_strlen(argv[i]) > 0)
				count++;
			i++;
		}
	}
	return (count);
}

void	cleaning_arg(t_data_maps *ptr)
{
	size_t	i;
	size_t	y;
	char	**new_argv;

	i = 0;
	y = 0;
	new_argv = malloc(sizeof(char *) * (count_index_empty(ptr->argv) + 1));
	if (new_argv != NULL)
	{
		while (ptr->argv[i])
		{
			if (ft_strlen(ptr->argv[i]) > 0)
			{
				new_argv[y] = ft_strdup(ptr->argv[i]);
				y++;
			}
			i++;
		}
		ft_clean_argv(ptr);
		new_argv[y] = NULL;
		ptr->argv = new_argv;
	}
}

void	trim(t_data_maps *ptr)
{
	size_t	i;
	char	*trim;

	i = 0;
	if (ptr->argv)
	{
		while (ptr->argv[i])
		{
			trim = ft_strtrim(ptr->argv[i], " 	");
			free(ptr->argv[i]);
			ptr->argv[i] = NULL;
			ptr->argv[i] = trim;
			i++;
		}
	}
	if (count_index_empty(ptr->argv) != i)
		cleaning_arg(ptr);
}

void	clear_and_open_path(char *str, t_mlx **mlx_ptr, int flags)
{
	size_t	i;
	char	*ptr;
	char	new_string[PATH_MAX];

	i = 0;
	new_string[i] = '\0';
	ptr = str + 2;
	while (*ptr == ' ' || *ptr == '	')
		ptr++;
	while (ptr != NULL && i < PATH_MAX && (*ptr != ' '
			&& *ptr != '	' && *ptr != '\0'))
	{
		new_string[i] = *ptr;
		i++;
		ptr++;
	}
	new_string[i] = '\0';
	(*mlx_ptr)->texture[flags] = mlx_xpm_file_to_image((*mlx_ptr)->mlx,
			new_string, &(*mlx_ptr)->txr_h[flags], &(*mlx_ptr)->txr_w[flags]);
	if (!(*mlx_ptr)->texture[flags])
		ft_free_all_and_exit((*mlx_ptr)->ptr_maps, MSG_ERROR_TX);
}

void	validazione(t_data_maps *maps)
{
	if ((maps->path_no && maps->path_ea && maps->path_we
			&& maps->path_so && maps->up_color && maps->down_color))
	{
		clear_and_open_path(maps->path_no, &maps->ptr_mlx, NO);
		clear_and_open_path(maps->path_so, &maps->ptr_mlx, SO);
		clear_and_open_path(maps->path_we, &maps->ptr_mlx, WE);
		clear_and_open_path(maps->path_ea, &maps->ptr_mlx, EA);
		check_and_charge_color(maps, maps->down_color, 'C');
		check_and_charge_color(maps, maps->up_color, 'F');
	}
	else
		ft_free_all_and_exit(maps, MSG_ERROR_ARG);
}
