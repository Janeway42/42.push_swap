/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:23:32 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/18 13:14:56 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_block_and_remainder(t_data *data)
{
	if (data->size <= 200)
		data->nr_blocks = 5;
	else
		data->nr_blocks = 11;
	data->block = data->size / data->nr_blocks;
	data->remainder = data->size % data->nr_blocks;
}

void	push_swap(t_data *data)
{
	if (data->size <= 5)
		sort_upto_five(data);
	else
	{
		presort_stack(data);
		find_block_and_remainder(data);
		sort_more_than_five(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 1)
		return (1);
	if (argc == 1)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		error_exit();
	data = set_data(data, argv);
	check_data(data);
	push_swap(data);
	final_free(data);
	return (0);
}
