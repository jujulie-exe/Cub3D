/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:35:29 by iwaslet           #+#    #+#             */
/*   Updated: 2025/05/22 18:37:48 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/render3d.h"
#include "../../include/cube3d.h"

void    draw_texture(t_mlx *mlx, t_ray *ray)
{}

void    get_texture(t_mlx *mlx, t_ray *ray)
{
    if (/*"0" a L/R du mur*/)
    {
        if (ray->var_x> 0)
            texture is EA;
        else
            texture is WE;
    }
    else
    {
        if (ray->var_y > 0)
            texture is SO;
        else
            texture is NO;
    }
}
/*textures pour NSWE -> NO SO WE EA NE ???
mlx->textures contient les 4 ???*/