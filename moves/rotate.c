/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/20 13:55:02 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 16:45:01 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	rotate(t_stack **x)
{
	t_stack	*new_last;
	t_stack	*old_last;

	new_last = *x;
	if (iterate(*x) == 2)
	{
		*x = (*x)->next;
		(*x)->next = new_last;
		new_last->prev = *x;
		new_last->next = NULL;
		(*x)->prev = NULL;
	}
	else
	{
		*x = (*x)->next;
		old_last = *x;
		while (old_last->next != NULL)
			old_last = old_last->next;
		old_last->next = new_last;
		new_last->prev = old_last;
		new_last->next = NULL;
		(*x)->prev = NULL;
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	write_ra(t_stack **a)
{
	if (iterate(*a) > 1)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	write_rb(t_stack **b)
{
	if (iterate(*b) > 1)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
}

void	write_rr(t_stack **a, t_stack **b)
{
	rotate_both(a, b);
	write(1, "ra\n", 3);
	write(1, "rb\n", 3);
}
