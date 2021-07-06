/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/04 14:00:18 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/04 14:00:43 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(const char *str, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlength(const char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_leftover(const char *str, char c)
{
	char	*dest;
	int		strlen_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strlen_str = ft_strlength(str, '\n');
	dest = malloc(sizeof(char) * (strlen_str + 1));
	if (!dest)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		dest[j] = str[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}
