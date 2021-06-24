/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 17:39:44 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/24 10:55:18 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void move_elem(t_data *data, t_stack **x, int number)
{
	int pos;

	pos = find_position(*x, number);
	if (pos == 1)
		return ;
	if (pos <= data->half)
	{
		while ( pos != 1)
		{
			write_ra(x);
			pos--;
		}
	}
	if (pos > data->half)
	{
		while (pos != iterate(*x) + 1)
		{
			write_rra(x);
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

void check_digit(char *str)
{
	if (*str == '-')
		str++;
	if (ft_isdigit(*str) == 1)
		str++;
	else
		error_exit();
}
