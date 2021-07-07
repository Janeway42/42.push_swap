/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/20 16:43:54 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 16:44:08 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	reverse_rotate(t_stack **x)
{
	t_stack	*new_first;
	t_stack	*new_last;

	new_first = (*x)->next;
	if (iterate(*x) == 2)
	{
		new_first->next = *x;
		(*x)->prev = new_first;
		(*x)->next = NULL;
		new_first->prev = NULL;
	}
	else
	{
		new_last = *x;
		while (new_first->next != NULL)
		{
			new_first = new_first->next;
			new_last = new_last->next;
		}
		new_first->next = *x;
		(*x)->prev = new_first;
		new_first->prev = NULL;
		new_last->next = NULL;
	}
	*x = new_first;
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	write_rra(t_stack **a)
{
	if (iterate(*a) > 1)
	{
		reverse_rotate(a);
		write (1, "rra\n", 4);
	}
}

void	write_rrb(t_stack **b)
{
	if (iterate(*b) > 1)
	{
		reverse_rotate(b);
		write (1, "rrb\n", 4);
	}
}

void	write_rrr(t_stack **a, t_stack **b)
{
	if (iterate(*a) > 1 && iterate(*b) > 1)
		rotate_both(a, b);
}
