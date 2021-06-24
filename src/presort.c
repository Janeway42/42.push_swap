/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   presort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 17:41:04 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/21 18:42:18 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void print_index(t_stack *c)  // ERASE print_index
//{
//	t_stack *temp;
//
//	temp = c;
//	if (temp == NULL)
//	{
//		printf("NULL\n");
//		return ;
//	}
//	while (temp->next != NULL)
//	{
//		printf("%d, ", temp->index);
//		temp = temp->next;
//	}
//	printf("%d \n", temp->index);
//}

static int *copy_list(t_stack **a, int *array) 
{
	t_stack *temp;
	int i;

	i = 0;
	temp = *a;
	while (temp!= NULL)
	{
		array[i] = temp->val;
		i++;
		temp = temp->next;
	}
	array[i] = '\0';
	return (array);
}

static int *sort_array(int *array, int size, t_data *data)
{
	int i;
	int temp;

	while (data->sort == 1)
	{
		data->sort = 0;
		i = 0;
		while (i < size)
		{			
			if (i != size - 1 && array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				data->sort = 1;
			}
//			printf("%d, ", array[i]);
			i++;
		}
//		printf("\n");
		continue ;
	}
	return (array);
}

static void add_index(int *array, t_data *data, int size)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = data->a;
	while (temp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (temp->val == array[i])
			{
				temp->index = i + 1;
//				printf("temp: %d\n", temp->val);
//				printf("index: %d\n", temp->index);
			}
			i++;
		}
		temp = temp->next;
	}
//	return (data->a);
}

void presort_stack(t_data *data)
{
	int *array;
	int size;

	size = iterate(data->a);
	array = malloc(sizeof(int) * size + 1);
	if (!array)
	{
		free(data);
		exit(1);
	}
	array = copy_list(&data->a, array);
	array = sort_array(array, size, data);
	add_index(array, data, size);
//	print_index(data->a);
	//free(array);
}