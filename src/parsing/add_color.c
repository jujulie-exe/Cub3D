/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:42:35 by jfranco           #+#    #+#             */
/*   Updated: 2025/06/13 17:26:39 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ (  */

#include "../../include/cube3d.h"

bool	digit_in_coma(char *l_coma, char *f_coma, char *str)
{
	size_t	len_first;
	size_t	len_middle;
	size_t	len_last;
	char	*tmp;

	len_first = (size_t)(f_coma - str);
	len_middle = (size_t)(l_coma - f_coma - 1);
	len_last = 0;
	tmp = l_coma + 1;
	while (tmp[len_last] != '\0')
		len_last++;
	if (len_first > 3 || len_middle > 3 || len_last > 3)
		return (false);
	return (true);
}

static	bool	pos_coma(char *str)
{
	char	*f_coma;
	char	*l_coma;

	f_coma = ft_strchr(str, ',');
	if (!f_coma || f_coma == str)
		return (false);
	l_coma = ft_strrchr(str, ',');
	if (!l_coma || l_coma == str)
		return (false);
	if (ft_isdigit((char)l_coma[-1]) && ft_isdigit((char)l_coma[1])
		&& ft_isdigit((char)f_coma[-1]) && ft_isdigit((char)f_coma[1])
		&& digit_in_coma(l_coma, f_coma, str))
		return (true);
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
	if ((digit >= 3) && vir == 2
		&& other == 0 && i >= 5 && ft_isdigit(str[i - 1]) && ft_isdigit(str[0])
		&& pos_coma(str))
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
	size_t		i;
	char		*tmp;
	int			rgb[3];
	long long	temp;

	i = 0;
	tmp = str + 1;
	while (*tmp == ' ' || *tmp == '	')
		tmp++;
	if (char_validity(tmp) == 0)
		ft_free_all_and_exit(ptr_maps, MSG_ERROR_COLOR);
	while (*tmp)
	{
		if (*tmp == ',')
			tmp++;
		temp = ft_atol(tmp);
		if (temp > 255 || i >= 3)
			ft_free_all_and_exit(ptr_maps, MSG_ERROR_MAX);
		else
			rgb[i] = temp;
		while (*tmp && ft_isdigit(*tmp))
			tmp++;
		i++;
	}
	create_rgb(rgb, c);
}
