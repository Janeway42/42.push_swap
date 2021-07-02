/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 17:39:44 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/02 19:19:18 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int find_half(t_stack *x)
{
	int size;
	int half;

	size = iterate(x);
	if (size % 2 == 0)
		half = size / 2;
	else
		half = size / 2 + 1;
	return (half);
}

void move_elem_a(t_stack **x, int number)
{
	int half;
	int pos;

	half = find_half(*x);
	pos = find_position(*x, number);
	if (pos == 1)
		return ;
	if (pos <= half)
	{
		while ( pos != 1)
		{
			write_ra(x);
			pos--;
		}
	}
	if (pos > half)
	{
		while (pos != iterate(*x) + 1)
		{
			write_rra(x);
			pos++;
		}
	}
}

void move_elem_b(t_stack **x, int number)
{
	int half;
	int pos;

	half = find_half(*x);
	pos = find_position(*x, number);
	if (pos == 1)
		return ;
	if (pos <= half)
	{
		while ( pos != 1)
		{
			write_rb(x);
			pos--;
		}
	}
	if (pos > half)
	{
		while (pos != iterate(*x) + 1)
		{
			write_rrb(x);
			pos++;
		}
	}
}


int find_min(t_stack *x)
{
	t_stack *temp;
	int min;

	temp = x;
	min = temp->val;
	while (temp != NULL)
	{
		if (temp->val < min)
			min = temp->val;
		temp = temp->next;
	}
	return (min);
}

int find_max(t_stack *x)
{
	t_stack *temp;
	int max;

	temp = x;
	max = temp->val;
	while (temp != NULL)
	{
		if (temp->val > max)
			max = temp->val;
		temp = temp->next;
	}
	return (max);
}

int find_position(t_stack *x, int number)
{
	t_stack *temp;
	int		location;

	location = 1;
	temp = x;
	while (temp->val != number)
	{
		temp = temp->next;
		location++;
	}
	return (location);
}

int check_sorted_reversed(t_stack *x)
{
	t_stack	*temp;

	temp = x;
	while (temp->next != NULL)
	{
		if (temp->val < temp->next->val)
			return (1);
		temp = temp->next;
	}
	return (0);
}
