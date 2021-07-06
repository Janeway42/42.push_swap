/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_more_than_five.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 13:37:06 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/03 14:58:04 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reorganize_and_insert(t_data *data, t_stack *temp)
{
	t_stack	*last;

	last = data->b;
	while (last->next != NULL)
		last = last->next;
	if (data->b->val > last->val)
		b_larger_than_last(data, temp, last);
	if (data->b->val < last->val)
		last_larger_than_b(data, temp, last);
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

void	sort_more_than_five(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nr_blocks)
	{
		run_block(data, (i * data->block), (i + 1) * data->block);
		i++;
	}
	if (data->remainder > 0)
		run_block(data, i * data->block, data->size);
	move_b_back(data);
}
