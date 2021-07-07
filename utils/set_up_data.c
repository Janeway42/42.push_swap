/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_up_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 16:05:56 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 16:48:37 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	fill_a(t_data *data)
{
	t_stack	*new;
	char	*str;
	int		num;

	data->argv++;
	while (*(data->argv))
	{
		str = *(data->argv);
		check_digit(data, str);
		num = ft_atoi(str, data);
		if (data->int_max == 1)
			error_free(data);
		new = create_new_elem(num);
		if (!new)
			error_free(data);
		add_at_the_end(&data->a, new);
		data->argv++;
	}
}

static t_data	*set_struct(t_data *data, char **argv)
{
	data->a = NULL;
	data->b = NULL;
	data->argv = argv;
	data->int_max = 0;
	data->int_max = 0;
	data->min = 0;
	data->max = 0;
	data->sort = 1;
	data->size = 0;
	data->nr_blocks = 0;
	data->block = 0;
	data->remainder = 0;
	return (data);
}

t_data	*set_data(t_data *data, char **argv)
{
	data = set_struct(data, argv);
	fill_a(data);
	if (check_sorted(data->a) == 0)
		free_exit(data);
	if (check_double(data->a) == 1)
		error_free(data);
	return (data);
}
