/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:32 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/25 16:44:15 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cube3d.h"
#include "../include/render3d.h"

int	main(int argc, char **argv) //proteger les mlx 
{
	t_data_maps	maps;
	t_mlx	ptr_mlx;

	maps = (struct s_data_maps){NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	ptr_mlx = (struct s_mlx){
	.mlx = NULL, 
	.texture[0] = NULL,
	.win = NULL,
	.img = NULL,//unsigned int
	.addr = NULL,
	.ptr_maps = NULL,
	.valid_map = NULL,
	.player = NULL,
	.ray = NULL,
	};
	if (argc != 2)
		return (ft_fprintf(2, "%s", MSG_ERROR), -1);
	ptr_mlx.ptr_maps = &maps;
	maps.ptr_mlx = &ptr_mlx;
	ptr_mlx.mlx= mlx_init();
	maps.name_maps = argv[1];
	proccesing_file_cub(&maps);
	printf("[all okay open server x11]");
	init_ptr_mlx(&ptr_mlx, &maps);
	ptr_mlx.win = mlx_new_window(ptr_mlx.mlx, ptr_mlx.height, ptr_mlx.width, "(っ´ω`c)");
	if (ptr_mlx.win == NULL)
		//mlx_error(1, &ptr_mlx);
	// ptr_mlx.img = mlx_new_image(ptr_mlx.img, ptr_mlx.height, ptr_mlx.width)
	// ptr_mlx.addr = mlx_get_data_addr(ptr_mlx.img, &ptr_mlx.bits_pixel,
	// 	&ptr_mlx.line_len, &ptr_mlx.endian);
	init_player(&ptr_mlx);
	init_ray(&ptr_mlx);
	mlx_key_hook(ptr_mlx.win, &key_press, &ptr_mlx);
//	mlx_hook(ptr_mlx.win, 17, (0), exit_key, &maps);
	mlx_loop_hook(ptr_mlx.mlx, draw_loop, &ptr_mlx);
	mlx_loop(ptr_mlx.mlx);
	return (0);
}
