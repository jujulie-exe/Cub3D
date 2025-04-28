/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:32 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/28 16:39:46 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/render3d.h"
#include "../include/cube3d.h"


int	main(int argc, char **argv)
{
	t_data_maps	maps;
	t_mlx	ptr_mlx;
	t_ray	ptr_ray;
	t_player	ptr_player;

	maps = (struct s_data_maps){NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	ptr_mlx = (struct s_mlx){
	.mlx = NULL, 
	.texture[0] = NULL,
	.win = NULL,
	.img = NULL,
	.addr = NULL,
	.ptr_maps = NULL,
	.valid_map = NULL,
	.player = &ptr_player,
	.ray = &ptr_ray,
	};
	if (argc != 2)
		return (ft_fprintf(2, "%s", MSG_ERROR), -1);
	ptr_mlx.ptr_maps = &maps;
	maps.ptr_mlx = &ptr_mlx;
	ptr_mlx.mlx= mlx_init();
	maps.name_maps = argv[1];
	proccesing_file_cub(&maps);
	init_player(&ptr_mlx);
	init_ray(&ptr_mlx);
	init_ptr_mlx(&ptr_mlx, &maps);
	if (ptr_mlx.win == NULL)
		//mlx_error(1, &ptr_mlx);
	return (0);
}
