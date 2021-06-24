/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_lists.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 16:26:33 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/21 11:14:52 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

t_stack *create_new_elem(int number)
{
	t_stack *new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->val = number;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void add_at_the_end(t_stack **x, t_stack *element)
{
	t_stack	*temp;

	temp = *x;
	if (*x != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = element;
		element->prev = temp;
	}
	else
		*x = element;
}

int iterate(t_stack *x)
{
	t_stack *temp;
	int		i;

	i = 0;
	temp = x;
	if (temp == NULL)
		return (0);
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void print_stack (t_stack *x)
{
	t_stack *temp;

	temp = x;
	if (temp == NULL)
	{
		printf("NULL\n");
		return ;
	}
	while (temp->next != NULL)
	{
		printf("%d, ", temp->val);
		temp = temp->next;
	}
	printf("%d \n", temp->val);
	printf("\n");
}