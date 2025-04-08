/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:48:24 by jfranco           #+#    #+#             */
/*   Updated: 2025/04/08 14:25:34 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#define MSG_ERROR_FILE "Error\n: The provided map cannot be opened. Please check that the file exists and is readable( ^..^)ﾉ\n"
#define MSG_ERROR_MAP "Error\n: Map not properly closed! ( ˘ ³˘)♥\n"
#define MSG_ERROR_FLAGS "Error\n: There must be exactly one spawn point.\n Please ensure that there are no more and no less༼つ ◕_◕ ༽つ\n"
#define MSG_ERROR_COLOR "Error\n: Invalid RGB format\n Use exactly three values (0-255), separated by commas(づ｡◕‿‿◕｡)づ\n "
#define MSG_ERROR_MAX "Error\n:  RGB value out of range\n Each value must be between 0 and 255.(︶︹︶)\n "
#define MSG_ERROR_ARG "Error\n: equired information is missing.\n Please ensure all necessary data is provided.(｡◕‿‿◕｡)\n"
#define DIV '#'
#define SIZE_WIN 2
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
#include <fcntl.h>
# include <X11/keysym.h>

#include <stdbool.h>
struct	s_mlx;


typedef struct	s_fill
{
	char	**copy_maps;
	size_t	x;
	size_t	y;
	char	target;
	char	color;
	
}	t_fill;

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
	int	txr_h[4];
	int	txr_w[4];
	int	width;
	int	height;
	int	bits_pixel;
	int	line_len;
	int	endian;
	unsigned int	*c_hex;
	unsigned int	*f_hex;
	char	**valid_map;
	size_t	p_x;
	size_t	p_y;

	t_data_maps	*ptr_maps;
	//t_player	*player; ou on cree une struct t_game qui contient mlx, maps et player ?
}	t_mlx;

// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
int	proccesing_file_cub(t_data_maps *maps);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	trim(t_data_maps *ptr);
void	validazione(t_data_maps *data);
void	swap_and_split(t_data_maps *maps, char *line);
char	*proccess_gnl(int fd);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/parsing_control_map.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
int	valid_position(char c);
int	serch_map_and_validate(char *str);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/flood_fill_algo.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	fill_flod(t_data_maps *ptr);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/add_color.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	check_and_charge_color(t_data_maps *ptr_maps, char *str, char c);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	ft_free_all_and_exit(t_data_maps *ptr_maps, char *str);
void	ft_clean_argv(t_data_maps *ptr_maps);
void	free_double_array(char ***ar);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/GNL/get_next_line.cc(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
char	*get_next_line(int fd);
// ♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡(っ´ω`c)(っ´ω`c)src/init_mlx_and_hook/mlx_init_ptr.c(っ´ω`c)(っ´ω`c)♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡
void	init_ptr_mlx(t_mlx *data, t_data_maps *ptr);
int	exit_key(t_data_maps *ptr);

#endif
