/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 13:23:05 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 15:01:33 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static void check_move(t_data *data, char *move)
{
	if (ft_strcmp(move, "sa") == 0)
		swap(&data->a);
	if (ft_strcmp(move, "sb") == 0)
		swap(&data->b);
	if (ft_strcmp(move, "ss") == 0)
	{
		swap (&data->a);
		swap (&data->b);
	}
	if (ft_strcmp(move, "pa") == 0)
		push(&data->a, &data->b);
	if (ft_strcmp(move, "pb") == 0)
		push(&data->b, &data->a);
	if (ft_strcmp(move, "ra") == 0)
		rotate(&data->a);
	if (ft_strcmp(move, "rb") == 0)
		rotate(&data->b);
	if (ft_strcmp(move, "rr") == 0)
	{
		rotate(&data->a);
		rotate(&data->b);
	}
	if (ft_strcmp(move, "rra") == 0)
		reverse_rotate(&data->a);
	if (ft_strcmp(move, "rrb") == 0)
		reverse_rotate(&data->b);
	if (ft_strcmp(move, "rrr") == 0)
	{
		reverse_rotate(&data->a);
		reverse_rotate(&data->a);
	}
	else
		error_exit();
}

int main (int argc, char **argv)
{
	t_data *data;
	char *move;

	if (argc < 2)
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		error_exit();
	data = set_data(data, argv);
	while (get_next_line(0, &move))
	{
		check_move(data, move);
		free(move);
	}
	if (check_sorted(data->a) == 0 && data->b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd ("KO\n", 1);
	free(data);
	return (0);
}