/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/20 12:17:34 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/29 18:18:50 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void swap(t_stack **x)
{
	t_stack *new_second;
	t_stack *third;

	if (iterate(*x) < 2)
		return ;
	new_second = *x;
	*x = (*x)->next;
	third = (*x)->next;

	(*x)->next = new_second;
	(new_second)->prev = *x;
	new_second->next = NULL;
	(*x)->prev = NULL;
	if (third) // if (third != NULL)
	{
		(new_second)->next = third;
		third->prev = new_second;
	}
}

void write_sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
//	print_stack(*a);
}

void write_sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
//	print_stack(*b);
}

void write_ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "sa\n", 3);
	write(1, "sb\n", 3);
}