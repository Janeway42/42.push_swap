/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/03 15:38:27 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/04 15:43:25 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void check_digit(t_data *data, char *str)
{
	if (*str == '-')
		str++;
	if (ft_isdigit(*str) == 1)
		str++;
	else
		error_free(data);
}

int check_double(t_stack *x)
{
	t_stack	*compared;
	t_stack	*temp;
	
	compared = x;
	while (compared != NULL)
	{
		temp = compared->next;
		while (temp != NULL)
		{
			if ((compared->val) == (temp->val))
				return (1);
			else
				temp = temp->next;
		}
		compared = compared->next;
	}
	return (0);
}

int check_sorted(t_stack *x)
{
	t_stack	*temp;

	temp = x;
	while (temp->next != NULL)
	{
		if (temp->val > temp->next->val)
			return (1);
		temp = temp->next;
	}
	return (0);
}