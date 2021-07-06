/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/04 14:27:42 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/04 15:02:22 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int i;

	if (s1 == s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[1])
		i++;
	return ((unsigned char) s1[i] - (unsigned char)s2[i]);
}

