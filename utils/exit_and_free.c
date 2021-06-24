/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_and_free.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:46:43 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/21 18:41:38 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	error_exit()
{
	ft_putstr_fd("Error A\n", 2);
	exit(1);
}

void error_int_max(t_data *data)
{
	ft_putstr_fd("Error B\n", 2);
	free(data);
	exit(1);
}