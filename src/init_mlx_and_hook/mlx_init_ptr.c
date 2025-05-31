/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:59:58 by jfranco           #+#    #+#             */
/*   Updated: 2025/05/30 18:32:22 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cube3d.h"
#include "../../include/render3d.h"

int	handle_key(int	keycode, t_data_maps *ptr)
{
	if (keycode == XK_Escape)
		exit_key(ptr);
	else if (keycode == XK_w)
		ptr->ptr_mlx->player->up = true;
	else if (keycode == XK_a)
		ptr->ptr_mlx->player->left = true;
	else if (keycode == XK_s)
		ptr->ptr_mlx->player->down = true;
	else if (keycode == XK_d)
		ptr->ptr_mlx->player->right = true;
	else if (keycode == XK_Left)
		ptr->ptr_mlx->player->rot_left = true;
	else if (keycode == XK_Right)
		ptr->ptr_mlx->player->rot_right= true;
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
	data->addr = mlx_get_data_addr(data->img,
			&data->bits_pixel,
			&data->line_len,
			&data->endian);
	mlx_hook(data->win, 17, (0), exit_key, &(*ptr));
	mlx_hook(data->win, 2, (1L<<0), handle_key, &(*ptr));
	mlx_loop_hook(data->mlx, draw_loop, &(*data));
	mlx_loop(data->mlx);
}
