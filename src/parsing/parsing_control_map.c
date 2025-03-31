/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_control_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:47:13 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/31 15:43:15 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ ( ˘ ³˘)♥ */

#include "../../include/cube3d.h"

int	valid_position(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int is_valid_map_char(char c)
{
    return (c == '0' || c == '1' || c == '2' || 
            c == 'N' || c == 'S' || c == 'E' || c == 'W' || 
            c == ' ' || c == '\n' || c == '	');
}

bool	control_map_proccess(char *str, size_t index)
{
	size_t	flags = 0;

	while (str[index])
	{
		if(!is_valid_map_char(str[index]) || flags > 1)
			return (false);
		if (valid_position(str[index]))
			flags++;
	index++;
	}
	if (flags == 1)
		return (true);
	return (false);
		
}

int	serch_map_and_validate(char *str)
{
	size_t	i;
	bool	valid;

	i = 0;
	valid = false;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			valid = control_map_proccess(str, i + 1);
		if (valid == true)
			break ;
		i++;
	}
	if (valid == true)
		return (str[i] = DIV, 1);
	return (0);
}
