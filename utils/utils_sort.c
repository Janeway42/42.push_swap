/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 17:39:44 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/07 19:17:23 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	find_half(t_stack *x)
{
	int	size;
	int	half;

	size = iterate(x);
	if (size % 2 == 0)
		half = size / 2;
	else
		half = size / 2 + 1;
	return (half);
}

void	move_elem_a(t_stack **x, int number)
{
	int	half;
	int	pos;

	half = find_half(*x);
	pos = find_position(*x, number);
	if (pos == 1)
		return ;
	if (pos <= half)
	{
		while (pos != 1)
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

void	move_elem_b(t_stack **x, int number)
{
	int	half;
	int	pos;

	half = find_half(*x);
	pos = find_position(*x, number);
	if (pos == 1)
		return ;
	if (pos <= half)
	{
		while (pos != 1)
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
