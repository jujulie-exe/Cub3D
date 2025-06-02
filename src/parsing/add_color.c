/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:42:35 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/02 18:17:13 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ (  */

#include "../../include/cube3d.h"

bool	check_div(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == DIV)
		{
			free(line);
			line = NULL;
			return (true);
		}
		i++;
	}
	return (false);
}

int	char_validity(char *str)
{
	size_t	i;
	size_t	vir;
	size_t	other;
	size_t	digit;

	i = 0;
	vir = 0;
	digit = 0;
	other = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			digit++;
		else if (str[i] == ',')
			vir++;
		else
			other++;
		i++;
	}
	if ((digit <= 9 && digit >= 3) && vir == 2
		&& other == 0 && i >= 5 && ft_isdigit(str[i - 1]) && ft_isdigit(str[0]))
		return (1);
	return (0);
}

int	create_rgb(int	*rgb, char c)
{
	static unsigned int	c_color = 0;
	static unsigned int	f_color = 0;

	if (c == 'C' && rgb != NULL)
	{
		c_color = ((rgb[R] & 0xFF) << 16)
			| ((rgb[G] & 0xFF) << 8) | (rgb[B] & 0xFF);
		return (0);
	}
	else if (c == 'F' && rgb != NULL)
	{
		f_color = ((rgb[R] & 0xFF) << 16)
			| ((rgb[G] & 0xFF) << 8) | (rgb[B] & 0xFF);
		return (0);
	}
	else if (c == 'F' && rgb == NULL)
		return (f_color);
	else if (c == 'C' && rgb == NULL)
		return (c_color);
	return (0);
}

void	check_and_charge_color(t_data_maps *ptr_maps, char *str, char c)
{
	size_t	i;
	char	*tmp;
	size_t	len;
	int		rgb[3];

	i = 0;
	tmp = str + 1;
	while (*tmp == ' ' || *tmp == '	')
		tmp++;
	len = ft_strlen(tmp);
	if (len > 11 || char_validity(tmp) == 0)
		ft_free_all_and_exit(ptr_maps, MSG_ERROR_COLOR);
	while (*tmp)
	{
		if (*tmp == ',')
			tmp++;
		rgb[i] = ft_atol(tmp);
		if (rgb[i] > 255)
			ft_free_all_and_exit(ptr_maps, MSG_ERROR_MAX);
		while (*tmp && ft_isdigit(*tmp))
			tmp++;
		i++;
	}
	create_rgb(rgb, c);
}
