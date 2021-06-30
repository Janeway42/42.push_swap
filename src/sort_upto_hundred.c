/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_upto_hundred.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 13:37:06 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/30 13:48:58 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reorganize_and_insert(t_data *data, t_stack *temp)
{
	t_stack	*last;
	int		smallest;

	last = data->b;
	if (temp->val < data->b->val)
	{
		smallest = find_min(data->b);
		while (temp->val < data->b->val && temp->val > smallest)
			write_rb(&data->b);
		write_pb(&data->a, &data->b);
		last = data->b;
		while (last->next != NULL)
		last = last->next;
		while (last->val > data->b->val)
			write_rrb(&data->b);
	}
	else
		write_pb(&data->a, &data->b);
}

static void	run_block(t_data *data, int min, int max)
{
	t_stack	*temp;

	temp = data->a;
	while (temp != NULL)
	{
		if (temp->index >= min && temp->index <= max)
		{
			move_elem(&data->a, temp->val);
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
			move_elem(&data->b, i);
			write_pa(&data->a, &data->b);
		}
	}
}

void	sort_upto_hundred(t_data *data, int size)
{
	int	block;
	int	nr_blocks;
	int	i;

	i = 0;
	nr_blocks = 5;
	block = size / nr_blocks;
	while (i < nr_blocks - 1)
	{
		run_block(data, (i * block), (i + 1) * block);
		i++;
	}
	run_block(data, i * block, size);
	move_b_back(data);
}
