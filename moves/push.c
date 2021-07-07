/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/20 13:16:04 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 16:58:14 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*moved_elem;

	moved_elem = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	moved_elem->next = NULL;
	if (*dest != NULL)
	{
		moved_elem->next = *dest;
		(*dest)->prev = moved_elem;
		moved_elem->prev = NULL;
	}
	*dest = moved_elem;
}

void	write_pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	push(a, b);
	write(1, "pa\n", 3);
}

void	write_pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	push(b, a);
	write(1, "pb\n", 3);
}
