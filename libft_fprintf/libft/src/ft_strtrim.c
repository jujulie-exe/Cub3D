/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:12:45 by jfranco           #+#    #+#             */
/*   Updated: 2024/10/24 13:49:54 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dove_sei(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	final;
	char	*dst;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	final = ft_strlen(s1);
	if ((final - 1) == 0)
		return (ft_strdup (""));
	while (s1[start] != '\0' && dove_sei(s1[start], set))
		start++;
	if (start == final)
		return (ft_strdup(""));
	while (final > 0 && dove_sei(s1[final - 1], set))
		final--;
	dst = (char *)malloc((final - start + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1 + start, final - start + 1);
	return (dst);
}
