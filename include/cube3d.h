/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:48:24 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/03 18:39:07 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define R 0
# define G 1
# define B 2
# define MSG_ERROR_TX "Error\n: Invalid texture or path.\n"
# define MSG_ERROR_CUB "Error\n: File must end with .cub.\n"
# define MSG_ERROR_EXT "Error\n: Missing .cub file extension.\n"
# define MSG_ERROR_FILE "Error\n: Cannot open map file.\n"
# define MSG_ERROR_MAP "Error\n: Map not properly closed.\n"
# define MSG_ERROR_FLAGS "Error\n: One spawn point required.\n"
# define MSG_ERROR_COLOR "Error\n: Use RGB: 3 values(0–255), comma-separated.\n"
# define MSG_ERROR_MAX "Error\n: RGB values must be 0–255.\n"
# define MSG_ERROR_ARG "Error\n: Missing required information.\n"
# define MSG_ERROR "Error\n"
# define DIV '#'
# define SIZE_WIN 2
# define BUFFER_SIZE 1

/*♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡*/

# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "../libft_fprintf/libft/src/libft.h"
# include "../libft_fprintf/ftprintf/src/ft_fprintf.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <stdbool.h>

struct	s_mlx;

typedef struct s_tex
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	double	current_pos;
	int		tex_y;
}	t_tex;

typedef struct s_median
{
	int				x;
	unsigned int	sum_t;
	unsigned int	sum_r;
	unsigned int	sum_g;
	unsigned int	sum_b;
	unsigned int	c;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	avg_r;
	unsigned int	avg_t;
	unsigned int	avg_g;
	unsigned int	avg_b;
}	t_median;

typedef struct s_fill
{
	char	**copy_maps;
	size_t	x;
	size_t	y;
	char	target;
	char	color;
}	t_fill;

typedef struct s_data_maps
{
	char			*name_maps;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*up_color;
	char			*down_color;
	char			*map;
	char			**argv;
	struct s_mlx	*ptr_mlx;

}	t_data_maps;

typedef struct s_wall
{
	int		index;
	char	*addr;
	int		bts;
	int		szl;
	int		height;
	int		width;
	int		edn;
	void	*texture;
}	t_wall;

typedef struct s_ray
{
	float	var_x;
	float	var_y;
	float	proj_x;
	float	proj_y;
	float	alpha;
	float	dtw;
	float	height;
	int		center_line;
	int		last_line;
	int		side;
	int		wall_step;
	int		tex_pos;
}	t_ray;

typedef struct s_player
{
	float	posx;
	float	posy;
	float	start_posx;
	float	start_posy;
	char	start_dir;
	int		dir_x;
	int		dir_y;
	int		step_x;
	int		step_y;
	bool	up;
	bool	down;
	bool	left;
	bool	right;

	float	angle;
	bool	rot_left;
	bool	rot_right;
}	t_player;

typedef struct s_mlx
{
	void			*mlx;
	void			*texture[4];
	void			*win;
	void			*img;
	void			*addr;
	int				txr_h[4];
	int				txr_w[4];
	int				width;
	int				height;
	int				bits_pixel;
	int				line_len;
	int				endian;
	unsigned int	*c_hex;
	unsigned int	*f_hex;
	char			**valid_map;
	size_t			p_x;
	size_t			p_y;
	float			draw_start;

	t_data_maps		*ptr_maps;
	t_player		*player;
	t_ray			*ray;
	t_wall			*wall;
}	t_mlx;

/*♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡*/
int		proccesing_file_cub(t_data_maps *maps);
// ♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡
void	trim(t_data_maps *ptr);
void	validazione(t_data_maps *data);
void	swap_and_split(t_data_maps *maps, char *line);
char	*proccess_gnl(int fd);
// ♡(っ´ω`c)(っ´ω`c)src/parsing/parsing_control_map.c(っ´ω`c)(っ´ω`c)♡
int		valid_position(char c);
int		serch_map_and_validate(char *str);
// ♡(っ´ω`c)(っ´ω`c)src/parsing/flood_fill_algo.c(っ´ω`c)(っ´ω`c)♡
void	fill_flod(t_data_maps *ptr);
// ♡(っ´ω`c)(っ´ω`c)src/parsing/add_color.c(っ´ω`c)(っ´ω`c)♡
void	check_and_charge_color(t_data_maps *ptr_maps, char *str, char c);
bool	check_div(char *line);
int		create_rgb(int	*rgb, char c);
// ♡(っ´ω`c)(っ´ω`c)src/parsing/proccess_parsing.c(っ´ω`c)(っ´ω`c)♡
void	ft_free_all_and_exit(t_data_maps *ptr_maps, char *str);
void	ft_clean_argv(t_data_maps *ptr_maps);
void	free_double_array(char ***ar);
// ♡(っ´ω`c)(っ´ω`c)src/parsing/controll_fill.c(っ´ω`c)(っ´ω`c)♡
bool	control_fill_map(t_fill *data);
// ♡(っ´ω`c)(っ´ω`c)src/GNL/get_next_line.cc(っ´ω`c)(っ´ω`c)♡
char	*get_next_line(int fd);
// ♡(っ´ω`c)(っ´ω`c)src/init_mlx_and_hook/mlx_init_ptr.c(っ´ω`c)(っ´ω`c)♡
void	init_ptr_mlx(t_mlx *data, t_data_maps *ptr);
int		exit_key(t_data_maps *ptr);

#endif
