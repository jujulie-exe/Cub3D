/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:48:24 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/28 17:14:21 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ */
#ifndef CUBE3D_H
#define CUBE3D_H

#define NO 0
#define SO 1
#define WE 2
#define NE 3
#define R 0
#define G 1
#define B 2
#define MSG_ERROR "Error\n"
#define MSG_ERROR_TX "Error\n: One or more textures are invalid. Please ensure that all texture files are in the correct format (.xpm) and accessible. Check that the texture paths are correct and the files are properly loaded."
#define MSG_ERROR_CUB "Error\n: Invalid file extension. The file must have a .cub extension.\n"
#define MSG_ERROR_EXT "Error\n: Missing file extension. Please provide a file with a .cub extension.\n"
#define MSG_ERROR_FILE "Error\n: The provided map cannot be opened. Please check that the file exists and is readable\n"
#define MSG_ERROR_MAP "Error\n"
#define MSG_ERROR_MAP "Error\n"
#define MSG_ERROR_COLOR "Error\n"
#define DIV '#'
#define WIDTH_XMP 300
#define HEIGHT_XMP 300
#define BUFFER_SIZE 1

#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "../libft_fprintf/libft/src/libft.h"
#include "../libft_fprintf/ftprintf/src/ft_fprintf.h"
#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"
#include <sys/stat.h>
#include <fcntl.h>

#include <stdbool.h>
struct	s_mlx;

typedef struct	s_data_maps
{
	char	*name_maps;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*up_color;
	char	*down_color;
	char	*map;
	char	**coord_map;
	char	**argv;
	struct s_mlx	*ptr_mlx;

}	t_data_maps;

typedef struct s_mlx
{
	void	*mlx;
	void	*texture[4];
	void	*win;
	void	*img;
	void	*addr;
	int	*f_hex
	int	*c_hex
	t_data_maps	*ptr_maps;

}	t_mlx;

// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
int	proccesing_file_cub(t_data_maps *maps);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	trim(t_data_maps *ptr);
void	validazione(t_data_maps *data);
void	swap_and_split(t_data_maps *maps, char *line);
char	*proccess_gnl(int fd);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/add_color.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	check_and_charge_color(t_data_maps *ptr_maps, char *str, char c);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	ft_free_all_and_exit(t_data_maps *ptr_maps, char *str);
void	ft_clean_argv(t_data_maps *ptr_maps);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/GNL/get_next_line.cc(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
char	*get_next_line(int fd);

#endif
