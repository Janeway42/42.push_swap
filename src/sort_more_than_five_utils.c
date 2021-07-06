/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_more_than_five_utils.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 13:37:06 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/03 15:00:20 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_larger_than_last(t_data *data, t_stack *temp, t_stack *last)
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

void	last_larger_than_b(t_data *data, t_stack *temp, t_stack *last)
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
