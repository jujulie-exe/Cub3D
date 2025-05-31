/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/31 19:46:14 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

unsigned int my_color_get(t_wall *wall, int y, int x)
{
	// img->data è un array di byte che rappresenta i pixel
    // img->bpp (bit per pixel), img->size_line (bytes per riga) e img->width/height ti aiutano a navigare
    // Puoi leggere o modificare i pixel in img->data con l’offset giusto
	//
	//return ((unsigned char *)&tex->img.addr[y * tex->img.line_length + x
	//		* (tex->img.bits_per_pixel / 8)]);
	//
	//char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
//	int bts;
//	int szl;
//	int	edn;
//	char *pixel_ptr = txt + (y * szl + x * bpp);
//	int	i = 0;
	int bpp = wall->bts / 8;
	char *pixel_ptr = wall->addr + (y * wall->szl + x * bpp);
	int	i = 0;
	unsigned int color = 0;
	 if (x < 0 || y < 0 || x >= wall->width || y >= wall->height)
        return (0); // oppure un colore "default"
	while (i < bpp)
	{
		color |= (unsigned char)pixel_ptr[i] << (8 * i);  // little-endian
		i++;
	}
	return (color);
}

void	init_texture(t_wall wall[], t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while(i < 3)
	{
		wall[i].index = 1;
		wall[i].texture = mlx->texture[i];
		wall[i].width = mlx->txr_w[i];
		wall[i].height = mlx->txr_h[i];
		wall[i].addr = mlx_get_data_addr(mlx->texture[i], &wall[i].bts, &wall[i].szl, &wall[i].edn);
		i++;
	}
}

int	get_texture(t_mlx *mlx, t_ray *ray, t_wall *wall[], int i)
{
	int	color;
	
	if (ray->side == 0)
	{
		if (ray->var_x > 0 && mlx->player->angle < PI / 4 || mlx->player->angle > 7 * PI / 4)
		{
			int tex_y = (int)(250 * mlx->wall[WE].height * (mlx->ray->center_line- mlx->draw_start) / i );

		    tex_y = tex_y % mlx->wall[WE].height;
		    tex_y = tex_y % mlx->wall[WE].height;
		    tex_y = tex_y % mlx->wall[WE].height;
		    tex_y = tex_y % mlx->wall[WE].height;
			color = my_color_get(&mlx->wall[WE],tex_y, mlx->ray->center_line);
		}
		else
		{
			color = 0xFA8072;
		}
	}
	else
	{
		if (ray->var_y < 0) // && mlx->player->angle < PI && mlx->player->angle > 0)
		{
			color = 0xFFD700;
		}
		else
		{
			color = 0x9ACD32;
		}
	}
	return (color);
}

// void	draw_texture(t_mlx *mlx, t_ray *ray)
// {
// 	int	y;
	
// 	y = 0;
// }

void	update_pixels(t_mlx *mlx, t_ray *ray, int x, int y)
{
	int	color;

//	init_texture(mlx->wall);
	color = get_texture(mlx, ray, &mlx->wall, y);
	my_put_pixel(x, y, color, mlx);
}

/*textures pour NSWE -> NO SO WE EA NE ???
mlx->textures contient les 4 ???*/
