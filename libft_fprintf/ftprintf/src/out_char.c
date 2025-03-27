/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:22:44 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/21 17:01:31 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	out_char(const int fd, int c)
{
	return (write(fd, &c, 1));
}

int	print_ad(const int fd, void *ptr)
{
	int long	count;
	uintptr_t	adress;

	count = 0;
	if (ptr == NULL)
	{
		return (write(fd, "0x0", 3));
	}
	adress = (uintptr_t)ptr;
	count += write(fd, "0x", 2);
	count += out_hex(fd, adress);
	return (count);
}
