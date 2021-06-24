/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:23:32 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/24 10:49:04 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_data *data)
{
	int size;

	size = iterate(data->a);
	if (size < 6)
		sort_upto_five(data, size);
	if (size > 5)
	{
		presort_stack(data);
		sort_upto_hundred(data, size);
	}
}

int main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		free(data);
		exit(1);
	}
	if (argc < 2)
		error_exit();
	data = set_data(data, argv);
	push_swap(data);
//	print_stack(data->a);
//	print_stack (data->b);
	// free

	return (0);
}
