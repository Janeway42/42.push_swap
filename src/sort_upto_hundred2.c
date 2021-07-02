/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_upto_hundred2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 13:37:06 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/02 18:36:45 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reorganize_and_insert(t_data *data, t_stack *temp)
{
	t_stack	*last;
//	int		smallest;

	last = data->b;
	while (last->next != NULL)
		last = last->next;


	if (data->b->val > last->val)
	{
		if (temp->val > data->b->val)
			write_pb(&data->a, &data->b);
		if (temp->val < last->val)
		{
			write_pb(&data->a, &data->b);
			write_rb(&data->b);
		}

		if (temp->val < data->b->val && temp->val > last->val)
		{
			while (data->b->val > temp->val)
				write_rb(&data->b);
			write_pb(&data->a, &data->b);
		}
	}
	if (data->b->val < last->val)
	{
		if (temp->val > last->val)
		{
			while (data->b->val < last->val)
			{
				last = last->prev;
				write_rrb(&data->b);
			}
			write_pb(&data->a, &data->b);
		}
		if (temp->val < data->b->val)
		{
			while (data->b->val < temp->val)
				write_rb(&data->b);
			write_pb(&data->a, &data->b);
		}
		if (temp->val > data->b->val && temp->val < last->val)
			write_pb(&data->a, &data->b);
	}
}

static void	run_block(t_data *data, int min, int max)
{
	t_stack	*temp;

	temp = data->a;
	while (temp != NULL)
	{
		if (check_sorted(data->a) == 0 && find_min(data->a) > find_max(data->b))
			return ;

		if (temp->index >= min && temp->index <= max)
		{
			move_elem_a(&data->a, temp->val);
			if (iterate(data->b) < 2)
				write_pb(&data->a, &data->b);
			else
				reorganize_and_insert(data, temp);
			temp = data->a;
		}
		else
			temp = temp->next;
	}
}

static void	move_b_back(t_data *data)
{
	int	i;

	while (data->b != NULL)
	{
		if (check_sorted_reversed(data->b) == 0)
		{
			while (data->b != NULL)
				write_pa(&data->a, &data->b);
			return ;
		}
		else
		{
			i = find_max(data->b);
			move_elem_b(&data->b, i);
			write_pa(&data->a, &data->b);
		}
	}
}

void	sort_upto_hundred(t_data *data, int size)
{
	int	block;
	int	nr_blocks;
	int	remainder;
	int	i;

	i = 0;
	nr_blocks = 5;
	block = size / nr_blocks;
	remainder = size % 5;
	while (i < nr_blocks)
	{
		run_block(data, (i * block), (i + 1) * block);
		i++;
	}
	if (remainder > 0)
		run_block(data, i * block, size);
	move_b_back(data);
}
