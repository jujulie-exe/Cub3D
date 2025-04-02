/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:59:58 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/02 17:53:09 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube3d.h"

void	re_size_win(t_mlx *data, int *w, int *h)
{
	int tmp_w;
	int tmp_h;

    tmp_h = (*h);
    tmp_w = tmp_h * 16 / 9;
    if (tmp_w > (*w) )
    {
        tmp_w = (*w);
        tmp_h = tmp_w * 9 / 16;
    }
    (*w) = tmp_w / SIZE_WIN;
    (*h) = tmp_h  / SIZE_WIN;
}

void	init_ptr_mlx(t_mlx *data)
{
	// get_dimesion_screen
	// applichiamo una formula per aver un rapporto 16:9;
	// e una dimesione intelligente dello schermo 
	// mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	re_size_win(data->mlx, &data->width, &data->height);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "(´・ω・)っ由 Ju & Isa (っ´ω`c)♡");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	/*data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian); */
}
