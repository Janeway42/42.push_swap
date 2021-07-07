/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/04 13:56:53 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 16:54:57 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_line(char *keep, char **line)
{
	if (!keep)
	{
		keep = malloc(sizeof(char) * 1);
		if (!keep)
			return (-1);
		keep[0] = '\0';
	}
	*line = ft_line(keep, '\0');
	free(keep);
	keep = NULL;
	return (0);
}

static int	has_line(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	create_line(char **line, char **keep, char *buff)
{
	char	*leftover;

	if (!*keep)
	{
		*keep = malloc(sizeof(char) * 1);
		if (!*keep)
			return (-1);
		*keep[0] = '\0';
	}
	*keep = ft_strjoin(*keep, buff);
	*line = ft_line(*keep, '\n');
	leftover = ft_leftover(*keep, '\n');
	free(*keep);
	*keep = leftover;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			bytes;
	static char	*keep;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (1);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		buff[bytes] = '\0';
		if (bytes == 0)
		{
			while (has_line(keep, '\n'))
				return (create_line(line, &keep, buff));
			return (free_line(keep, line));
		}
		if (has_line(buff, '\n'))
			return (create_line(line, &keep, buff));
		keep = ft_strjoin(keep, buff);
	}
	return (0);
}
