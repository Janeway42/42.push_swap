/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_upto_five.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 17:15:03 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/03 15:25:18 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **x)
{
	int	top;
	int	middle;
	int	botom;

	top = (*x)->val;
	middle = ((*x)->next)->val;
	botom = (((*x)->next)->next)->val;
	if (middle < botom && middle < top && top < botom)
		write_sa(x);
	else if (middle > botom && middle < top && top > botom)
	{
		write_sa(x);
		write_rra(x);
	}
	else if (middle < botom && middle < top && top > botom)
		write_ra(x);
	else if (middle > botom && middle > top && top < botom)
	{
		write_sa(x);
		write_ra(x);
	}
	else if (middle > botom && middle > top && top > botom)
		write_rra(x);
}

static void	sort_four(t_data *data)
{
	int	min;

	min = find_min(data->a);
	move_elem_a(&data->a, min);
	write_pb(&data->a, &data->b);

	if (check_sorted(data->a) == 1)
		sort_three(&data->a);
	write_pa(&data->a, &data->b);
}

static void sort_five(t_data *data)
{
	int	min;

	min = find_min(data->a);
	move_elem_a(&data->a, min);
	write_pb(&data->a, &data->b);

	min = find_min(data->a);
	move_elem_a(&data->a, min);
	write_pb(&data->a, &data->b);

	if (check_sorted(data->a) == 1)
		sort_three(&data->a);
	write_pa(&data->a, &data->b);
	write_pa(&data->a, &data->b);
}


void sort_upto_five(t_data *data)
{
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		write_sa(&data->a);
	else if (data->size == 3)
		sort_three(&data->a);
	else if (data->size == 4)
		sort_four(data);
	else if (data->size == 5)
		sort_five(data);
}
