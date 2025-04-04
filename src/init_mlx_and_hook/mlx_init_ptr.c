/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:59:58 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/04 12:22:02 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube3d.h"

int	handle_key(int	keycode, t_data_maps *ptr)
{
	if (keycode == XK_Escape)
		exit_key(ptr);
	else if (keycode == XK_w)
		mlx_put_image_to_window(ptr->ptr_mlx->mlx, ptr->ptr_mlx->win, ptr->ptr_mlx->texture[0], 0, 0);
	else if (keycode == XK_a)
		mlx_put_image_to_window(ptr->ptr_mlx->mlx, ptr->ptr_mlx->win, ptr->ptr_mlx->texture[1], 0, 0);
	else if (keycode == XK_s)
		mlx_put_image_to_window(ptr->ptr_mlx->mlx, ptr->ptr_mlx->win, ptr->ptr_mlx->texture[2], 0, 0);
	else if (keycode == XK_d)
		mlx_put_image_to_window(ptr->ptr_mlx->mlx, ptr->ptr_mlx->win, ptr->ptr_mlx->texture[3], 0, 0);
	return (0);
}

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

void	init_ptr_mlx(t_mlx *data, t_data_maps *ptr)
{
	// get_dimesion_screen
	// applichiamo una formula per aver un rapporto 16:9;
	// e una dimesione intelligente dello schermo 
	// mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	re_size_win(data->mlx, &data->width, &data->height);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "(´・ω・)っ由 Ju & Isa (っ´ω`c)♡");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	mlx_hook(data->win, 17, (0), exit_key, &(*ptr));
	mlx_hook(data->win, 2, (1L<<0), handle_key, &(*ptr));
	/*data->addr = mlx_get_data_addr(data->img,
			&data->bits_per_pixel,
			&data->line_length,
			&data->endian); */
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
}
