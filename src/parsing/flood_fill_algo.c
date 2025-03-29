typedef struct	s_fill
{
	char	**copy_maps;
	size_t	x;
	size_t	y;
	size_t	h;
	size_t	w;
	char	target;
	char	color;
	
}	t_fill;

void	fill_flod(t_data_maps *ptr)
{
	copy_maps = ft_split(ptr->map, '\n');
	flood_fill_algo();
	
}
