/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:14:52 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/18 16:13:00 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	intlen(int nb)
{
	size_t	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int long	num;
	size_t		i;
	char		*dst;

	num = n;
	i = intlen(n);
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	dst[i] = '\0';
	if (num == 0)
		dst[0] = '0';
	else if (num < 0)
	{
		dst[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		dst[--i] = (num % 10) + '0';
		num /= 10;
	}
	return (dst);
}
