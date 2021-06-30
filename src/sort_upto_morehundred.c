/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_upto_morehundred.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 13:37:06 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/30 14:10:45 by janeway       ########   odam.nl         */
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

static t_stack *find_forward(t_data *data, int min, int max)
{
	t_stack *forward;
	
	forward = data->a;
	while (forward != NULL)
	{
		if (forward->index >= min && forward->index <= max)
			return (forward);
		forward = forward->next;
	}
	return ((void *)NULL);
}

static t_stack *find_backward(t_data *data, int min, int max)
{
	t_stack *backward;
	
	backward = data->a;
	if (backward == NULL)
		return ((void *)NULL);
	while (backward->next != NULL)
		backward = backward->next;
	
	while (backward != NULL)
	{
		if (backward->index >= min && backward->index <= max)
			return (backward);
		backward = backward->prev;
	}
	return ((void *)NULL);
}

static void run_block(t_data *data, int min, int max)
{
	t_stack *forward;
	t_stack *backward;
	int		size;
	int		pos_f;
	int		pos_b;

	size = iterate(data->a);
	forward = find_forward(data, min, max);
	backward = find_backward(data, min, max);

	while (forward != NULL && backward != NULL)
	{
		if (forward == backward)
		{
			pos_f = find_position(data->a, forward->val);
			move_elem(&data->a, forward->val);
		}
	
		else if (forward != NULL && backward != NULL)
		{
			pos_f = find_position(data->a, forward->val);
			pos_b = find_position(data->a, backward->val);

			if (pos_f == pos_b && pos_f != 1)
				move_elem(&data->a, forward->val);
			if (pos_f - 1 > (size - pos_b + 1))
				move_elem(&data->a, backward->val);
			if (pos_f - 1 <= (size - pos_b + 1))
				move_elem(&data->a, forward->val);
		}
		if (iterate(data->b) < 2)
				write_pb(&data->a, &data->b);
		else
			reorganize_and_insert(data, data->a);

		forward = find_forward(data, min, max);
		backward = find_backward(data, min, max);
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
		}
		else
		{
			i = find_max(data->b);
			move_elem(&data->b, i);
			write_pa(&data->a, &data->b);
		}
	}
}

void sort_upto_morehundred(t_data *data, int size)
{
	int	block;
	int	nr_blocks;
	int	i;
	int total;

	i = 0;
	total = find_max(data->a) - find_min(data->a);
	size = total;
	nr_blocks = 11;
	block = total / nr_blocks;

	while (i < nr_blocks - 1)
	{
		run_block(data, (i * block), (i + 1) * block);
		i++;
	}
	run_block(data, i * block, size);
	move_b_back(data);
}