/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/03 15:18:23 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/03 15:18:27 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*result;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	result = malloc(nitems * size);
	if (!result)
		return (NULL);
	ft_bzero(result, nitems * size);
	return (result);
}
