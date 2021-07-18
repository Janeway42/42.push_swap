/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   presort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 17:41:04 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/18 11:11:47 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*copy_list(t_stack **a, int *array)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = 0;
	while (temp != NULL)
	{
		array[i] = temp->val;
		i++;
		temp = temp->next;
	}
	return (array);
}

static int	*sort_array(int *array, t_data *data)
{
	int	i;
	int	temp;

	while (data->sort == 1)
	{
		data->sort = 0;
		i = 0;
		while (i < data->size)
		{
			if (i != data->size - 1 && array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				data->sort = 1;
			}
			i++;
		}
		continue ;
	}
	return (array);
}

static void	add_index(int *array, t_data *data, int size)
{
	t_stack	*temp;
	int		i;

	temp = data->a;
	while (temp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (temp->val == array[i])
				temp->index = i + 1;
			i++;
		}
		temp = temp->next;
	}
}

void	presort_stack(t_data *data)
{
	int	*array;

	array = calloc(sizeof(int), data->size + 1);
	if (!array)
		error_free_exit(data);
	array = copy_list(&data->a, array);
	array = sort_array(array, data);
	add_index(array, data, data->size);
	free(array);
}
