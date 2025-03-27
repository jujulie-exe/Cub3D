/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:33:20 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/17 14:12:23 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	l1;
	size_t	l2;
	size_t	total;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	total = l1 + l2 + 1;
	cat = (char *) malloc((total) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	ft_strlcpy(cat, s1, l1 + 1);
	ft_strlcat(cat, s2, total);
	return (cat);
}
