/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:56:25 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/26 15:59:05 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ */

#include "../../include/cube3d.h"

void ft_clean_argv(t_data_maps *ptr_maps)
{
	size_t	i;

	i = 0;
	if (ptr_maps->argv != NULL)
	{
		while(ptr_maps->argv[i] != NULL)
		{
			free(ptr_maps->argv[i]);
			ptr_maps->argv[i] = NULL;
			i++;

		}
		free(ptr_maps->argv);
		ptr_maps->argv = NULL;
	}
}

void	ft_clean_texture(t_mlx *ptr)
{
	size_t	i;

	i = 0;
	while (ptr->texture[i])
	{
		free(ptr->texture[i]);
		ptr->texture[i] = NULL;
		i++;

	}
	//free(ptr->texture);
	//ptr->texture = NULL;

}

void	ft_clean_mlx(t_mlx *ptr)
{
	if (ptr->img)
	{
		mlx_destroy_image(ptr->mlx, ptr->img);
		ptr->img = NULL;
	}
	if (ptr->win)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		ptr->win = NULL;
	}
	if (ptr->texture)
		ft_clean_texture(ptr);
	if (ptr->mlx)
		mlx_destroy_display(ptr->mlx);
	if (ptr->mlx)
	{
		free(ptr->mlx);
		ptr->mlx = NULL;
	}
}

void	ft_free_all_and_exit(t_data_maps *ptr_maps, char *str)
{
	if (str)
		ft_fprintf(2, "%s", str);
	if (ptr_maps)
	{
		ft_clean_argv(ptr_maps);
		if (ptr_maps->ptr_mlx)
			ft_clean_mlx(ptr_maps->ptr_mlx);
	}
	exit(-1);
}
