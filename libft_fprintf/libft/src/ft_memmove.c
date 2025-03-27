/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:49 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/15 12:24:16 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*sr;

	i = 0;
	dest = (unsigned char *)dst;
	sr = (const unsigned char *)src;
	if (dest < sr)
	{
		while (i < len)
		{
			dest[i] = sr[i];
			i++;
		}
	}
	else if (dest > sr)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = sr[i];
		}
	}
	return (dst);
}
