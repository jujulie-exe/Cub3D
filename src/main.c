/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:32 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/31 18:45:51 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/render3d.h"
#include "../include/cube3d.h"
#include "../include/render3d.h"

int	main(int argc, char **argv)
{
	t_data_maps	maps;
	t_mlx		ptr_mlx;
	t_ray		ptr_ray;
	t_player	ptr_player;
	t_wall		ptr_wall[4];

	if (argc != 2)
		return (ft_fprintf(2, "%s", MSG_ERROR_ARGC), -1);
	maps = (struct s_data_maps){0};
	ptr_mlx = (struct s_mlx){0};
	ptr_mlx.texture[0] = NULL;
	ptr_mlx.player = &ptr_player;
	ptr_mlx.ray = &ptr_ray;
	ptr_mlx.wall = ptr_wall;
	ptr_mlx.ptr_maps = &maps;
	maps.ptr_mlx = &ptr_mlx;
	ptr_mlx.mlx = mlx_init();
	if (ptr_mlx.mlx == NULL)
		return (ft_fprintf(2, "%s", MSG_ERROR_MLX), -1);
	maps.name_maps = argv[1];
	proccesing_file_cub(&maps);
	init_player(&ptr_mlx);
	init_texture(ptr_wall, &ptr_mlx);
	init_ptr_mlx(&ptr_mlx, &maps);
	return (0);
}
