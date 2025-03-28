/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:42:35 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/28 18:43:50 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// aggiungere include
//
//
//

#include "../../include/cube3d.h"
void	check_and_charge_color(t_data_maps *ptr_maps)
{
	size_t	i;
	char *tmp;
	size_t	len;

	i = 0;
	tmp = ptr_maps->up_color + 1;
	while (*tmp == ' ' || *tmp == '	')
		tmp++;
	len = ft_strlen(tmp);
	int deb;
	/* aggiungere una funzione per verficare che ci siano solo
	 * carrateri validi con la giustat quantita massimo 9 digit 3 ,*/
	if (len > 12 || char_validy(tmp))
		return ;
	else
	{
		while (*tmp)
		{	
			if (*tmp == ',')
				tmp++;
			if ((deb = ft_atol(tmp)) >= 255)
				ft_free_all_and_exit(ptr_maps, MSG_ERROR);
			while (*tmp && ft_isdigit(*tmp) )
				tmp++;
		}
	}
}
