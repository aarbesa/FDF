/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:44:44 by aabdyli           #+#    #+#             */
/*   Updated: 2023/09/05 19:44:50 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

/* If there is one, this function will return the position 
 * of the start of the newline + 1, to ensure that the
 * \n is keeped. */

int	ft_return_n_position_in_string(const char *s, int c)
{
	int	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == (char) c)
			return (i + 1);
		i++;
	}
	return (0);
}

/* This function will create a string that contains both what
 * has just been read, and what had been read of the previous read().
 * It will free the existing string that has been joined.
 * It will return only what has just been read if nothing else
 * had been read before in this while loop.
 * Return Value : Whats has been read so far in this gnl call*/

char	*ft_customized_strjoin_with_free(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen((char *)s1) + 1);
	ft_strlcpy(&str[ft_strlen((char *) s1)], s2, ft_strlen((char *)s2) + 1);
	free((char *) s1);
	if (!str)
		return (NULL);
	return (str);
}

/* This function will stash a string in the static variable stash.
 * The stashed string is what comes after a newline.
 * It is also used to free the sent variable that has became useless.
 * Return Value : The newline to be returned */

char	*ft_split_and_free(char *line, char *stash, char *free1, char *free2)
{
	int			i;
	char		*ligne;

	if (!line)
		return (NULL);
	if (ft_strlen(stash) == 0 && free1 == NULL)
		return (NULL);
	i = ft_return_n_position_in_string(line, '\n');
	ligne = malloc(i + 1);
	if (!ligne)
		return (NULL);
	ft_strlcpy(ligne, line, i + 1);
	ft_strlcpy(stash, &line[i], ft_strlen(&line[i]) + 1);
	free(free1);
	if (free2 != NULL)
		free(free2);
	return (ligne);
}

/* If stash is NOT empty, it will be duplicated and erased.
 * Return Value : What was in stash */

char	*give_to_line_what_is_stashed(char *stash)
{
	char	*line;

	if (ft_strlen(stash))
	{
		line = ft_strdup(stash);
		if (!line)
			return (NULL);
		ft_bzero(stash, 1);
	}
	else
		line = NULL;
	return (line);
}

/* This function is the main one.
 * Return Value : The line to be read from the File Descriptor */

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	stash[FOPEN_MAX][BUFFER_SIZE];

	if (fd >= FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (buf = NULL);
	if (ft_return_n_position_in_string(stash[fd], '\n'))
		return (line = ft_split_and_free(stash[fd], stash[fd], NULL, NULL));
	line = give_to_line_what_is_stashed(stash[fd]);
	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		if (!line)
			line = ft_calloc(1, 1);
		line = ft_customized_strjoin_with_free(line, buf);
		ft_bzero(buf, BUFFER_SIZE);
		if (ft_return_n_position_in_string(line, '\n'))
			return (ft_split_and_free(line, stash[fd], line, buf));
	}
	free(buf);
	return (line);
}
