/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:32 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/03 13:59:18 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render3d.h"
#include "../include/cube3d.h"
#include "../include/render3d.h"

int	main(int argc, char **argv) //proteger les mlx 
{
	t_data_maps	maps;
	t_mlx		ptr_mlx;
	t_ray		ptr_ray;
	t_player	ptr_player;
	t_wall		ptr_wall[4];

	maps = (struct s_data_maps){NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	ptr_wall[0] = (struct s_wall){0, NULL, 0, 0, 0, 0, 0, NULL};
	ptr_wall[1] = (struct s_wall){0, NULL, 0, 0, 0, 0, 0, NULL};
	ptr_wall[2] = (struct s_wall){0, NULL, 0, 0, 0, 0, 0, NULL};
	ptr_wall[3] = (struct s_wall){0, NULL, 0, 0, 0, 0, 0, NULL};
	ptr_mlx = (struct s_mlx){
		.mlx = NULL,
		.texture[0] = NULL,
		.win = NULL,
		.img = NULL, //unsigned int
		.addr = NULL,
		.ptr_maps = NULL,
		.valid_map = NULL,
		.player = &ptr_player,
		.ray = &ptr_ray,
		.wall = ptr_wall,
	};
	if (argc != 2)
		return (ft_fprintf(2, "%s", MSG_ERROR), -1);
	ptr_mlx.ptr_maps = &maps;
	maps.ptr_mlx = &ptr_mlx;
	ptr_mlx.mlx = mlx_init();
	maps.name_maps = argv[1];
	proccesing_file_cub(&maps);
	init_player(&ptr_mlx);
	init_texture(ptr_wall, &ptr_mlx);
	init_ptr_mlx(&ptr_mlx, &maps);
	if (ptr_mlx.win == NULL)
		//mlx_error(1, &ptr_mlx);
	return (0);
}
