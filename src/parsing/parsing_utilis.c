/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:15:22 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/31 16:19:13 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

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
	char **new_argv = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (ptr->argv[i])
	{
		if(ft_strlen(ptr->argv[i]) > 0 )
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

void	clear_and_open_path(char *str, t_mlx *mlx_ptr, int flags)
{
	size_t	i;
	char	*ptr;
	char	new_string[PATH_MAX];

	i = 0;
	new_string[i] = '\0';
	ptr = str + 2;
	while (*ptr == ' ' || *ptr == '	')
		ptr++;
	while (ptr != NULL &&  i < PATH_MAX && (*ptr != ' ' && *ptr != '	' && *ptr != '\0'))
	{
		new_string[i] = *ptr;
		i++;
		ptr++;
	}
//	mlx_ptr->texture[flags] = mlx_xpm_file_to_image(mlx_ptr->mlx, new_string, (int *)WIDTH_XMP, (int *)HEIGHT_XMP);
//	if (!mlx_ptr->texture[flags])
//		ft_free_all_and_exit(mlx_ptr->ptr_maps, MSG_ERROR_TX);
}

void	validazione(t_data_maps *maps)
{
	if ((maps->path_no &&  maps->path_ea && maps->path_we && maps->path_so && maps->up_color && maps->down_color))
	{
		clear_and_open_path(maps->path_no, maps->ptr_mlx, NO);
		clear_and_open_path(maps->path_so, maps->ptr_mlx, SO);
		clear_and_open_path(maps->path_we, maps->ptr_mlx, WE);
		clear_and_open_path(maps->path_ea, maps->ptr_mlx, NE);
		check_and_charge_color(maps, maps->down_color, 'C');
		check_and_charge_color(maps, maps->up_color, 'F');
	}
	else
		ft_free_all_and_exit(maps, "NO");
}
	
