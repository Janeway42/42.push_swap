/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_upto_hundred.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 13:37:06 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/21 19:12:47 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void run_block(t_data *data, int min, int max)
{
	t_stack *temp;

	temp = data->a;
//	printf("min: %d max: %d\n", min, max);
	while (temp != NULL)
	{
		if (temp->index >= min && temp->index <= max)
		{
			move_elem(data, &data->a, temp->val);
			write_pb(&data->a, &data->b);
			temp = data->a;
		}
		else
			temp = temp->next;
	}
}

static void move_b_back(t_data *data)
{
	int	i;

	while (data->b != NULL)
	{
		i = find_max(data->b);
		move_elem(data, &data->b, i);
		write_pa(&data->a, &data->b);
	}
}

void sort_upto_hundred(t_data *data, int size)
{
	int block;

	block = size / 5;

	if (size % 2 == 0)
		data->half = size / 2;
	else 
		data->half = size / 2 + 1;

	run_block(data, 1, 1 * block);
	run_block(data, 1 * block, 2 * block);
	run_block(data, 2 * block, 3 * block);
	run_block(data, 3 * block, 4 * block);
	run_block(data, 4 * block, size); 

	move_b_back(data);

}