/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:23:32 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/02 18:52:25 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_swap(t_data *data)
{
	int	size;

	size = iterate(data->a);
	if (size <= 5)
		sort_upto_five(data, size);
	else
	{
		presort_stack(data, size);
		if (size <= 200)
		{
			sort_upto_hundred(data, size);
		}
		else
			sort_upto_morehundred(data, size);
	}
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		error_exit();

	data = malloc(sizeof(t_data));
	if (!data)
		error_exit();

	data = set_data(data, argv);
	push_swap(data);
//	print_stack(data->a);
//	print_stack (data->b);
//	if (check_sorted(data->a) == 1)
//		printf("not sorted\n");
	free (data);
	return (0);
}
