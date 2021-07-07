/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sort2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/06 17:21:23 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 17:21:43 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	find_min(t_stack *x)
{
	t_stack	*temp;
	int		min;

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

int	find_max(t_stack *x)
{
	t_stack	*temp;
	int		max;

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

int	find_position(t_stack *x, int number)
{
	t_stack	*temp;
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
