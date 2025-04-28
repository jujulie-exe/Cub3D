/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:32 by jfranco           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/04/04 11:34:20 by jfranco          ###   ########.fr       */
=======
/*   Updated: 2025/04/28 16:13:58 by jfranco          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */


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
<<<<<<< Updated upstream
=======
	.player = &ptr_player,
	.ray = &ptr_ray,
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
	
//	mlx_hook(ptr_mlx.win, 17, (0), exit_key, &maps);
	mlx_loop(ptr_mlx.mlx);
=======
	if (ptr_mlx.win == NULL)
		//mlx_error(1, &ptr_mlx);
>>>>>>> Stashed changes
	return (0);
}
