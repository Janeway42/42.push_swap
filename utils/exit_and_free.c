/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_and_free.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:46:43 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/03 14:33:06 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	error_exit()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_free(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	free(data);
	exit(1);
}

void	free_exit(t_data *data)
{
	free(data);
	exit(1);
}
