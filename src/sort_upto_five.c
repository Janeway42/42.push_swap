/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_upto_five.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 17:15:03 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/21 13:31:49 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **x)
{
	int top; 
	int middle;
	int botom;

	top = (*x)->val;
	middle = ((*x)->next)->val;
	botom = (((*x)->next)->next)->val;
	if (middle < botom && middle  < top && top < botom)
		write_sa(x);
	if (middle > botom && middle  < top && top > botom)
	{
		write_sa(x);
		write_rra(x);
	}
	if (middle < botom && middle  < top && top > botom)
		write_ra(x);
	if (middle > botom && middle  > top && top < botom)
	{
		write_sa(x);
		write_ra(x);
	}
	if (middle > botom && middle  > top && top > botom)
		write_rra(x);
}

void sort_four(t_data *data)
{
	int min;

	min = find_min(data->a);
	move_elem(data, &data->a, min);
	write_pb(&data->a, &data->b);

	if (check_sorted(data->a) == 1)
		sort_three(&data->a);
	write_pa(&data->a, &data->b);
}

void sort_five(t_data *data)
{
	int min; 

	min = find_min(data->a);
	move_elem(data, &data->a, min);
	write_pb(&data->a, &data->b);

	min = find_min(data->a);
	move_elem(data, &data->a, min);
	write_pb(&data->a, &data->b);

	if (check_sorted(data->a) == 1)
		sort_three(&data->a);
	write_pa(&data->a, &data->b);
	write_pa(&data->a, &data->b);
}


void sort_upto_five(t_data *data, int size)
{
	if (size % 2 == 0)
		data->half = size / 2;
	else 
		data->half = size / 2 + 1;

	if (size == 1)
		return ;
	else if (size == 2)
		write_sa(&data->a);
	else if ( size == 3)
		sort_three(&data->a);
	else if (size == 4)
		sort_four(data);
	else if (size == 5)
		sort_five(data); 
}