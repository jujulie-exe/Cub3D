/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:46:03 by jfranco           #+#    #+#             */
/*   Updated: 2025/03/25 18:09:53 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

static char	*read_new_line(int fd, char *stash)
{
	char		*temp;
	ssize_t		bytes;
	char		buffer[BUFFER_SIZE + 1];

	bytes = 1;
	while (bytes > 0 && (!stash || !ft_strchr(stash, '\n')))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (stash == NULL)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (stash == NULL)
			return (NULL);
	}
	return (stash);
}

static char	*fill_new_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	if (stash[i] == '\0')
	{
		line = (char *)malloc((i + 1) * sizeof(char));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, stash, i + 1);
	}
	else
	{
		line = malloc((i + 2) * sizeof(char));
		if (line == NULL)
			return (NULL);
		ft_strlcpy(line, stash, i + 2);
	}
	return (line);
}

static char	*clear_stash(char *stash)
{
	char			*update_stash;
	size_t			len;
	unsigned int	j;

	len = ft_strlen(stash);
	j = 0;
	while (stash[j] != '\n' && stash[j] != '\0')
		j++;
	if (stash[j] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	update_stash = ft_substr(stash, j + 1, (len - j) + 1);
	free(stash);
	stash = NULL;
	if (update_stash == NULL || ft_strlen(update_stash) == 0)
	{
		free(update_stash);
		update_stash = NULL;
		return (NULL);
	}
	return (update_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[254];

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = read_new_line(fd, stash[fd]);
	if (stash[fd] == NULL || ft_strlen(stash[fd]) == 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = fill_new_line(stash[fd]);
	if (line == NULL)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = clear_stash(stash[fd]);
	return (line);
}
