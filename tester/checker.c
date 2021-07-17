/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 13:23:05 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/17 17:46:08 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static void	error_move(t_data *data, char *move)
{
	ft_putstr_fd("KO\n", 1);
	free(move);
	free_stack(&data->a);
	free(data);
	exit(1);
}

static void	check_move(t_data *data, char *move)
{
	if (ft_strcmp(move, "sa") == 0)
		swap(&data->a);
	else if (ft_strcmp(move, "sb") == 0)
		swap(&data->b);
	else if (ft_strcmp(move, "ss") == 0)
		swap_both(&data->a, &data->b);
	else if (ft_strcmp(move, "pa") == 0)
		push(&data->a, &data->b);
	else if (ft_strcmp(move, "pb") == 0)
		push(&data->b, &data->a);
	else if (ft_strcmp(move, "ra") == 0)
		rotate(&data->a);
	else if (ft_strcmp(move, "rb") == 0)
		rotate(&data->b);
	else if (ft_strcmp(move, "rr") == 0)
		rotate_both(&data->a, &data->b);
	else if (ft_strcmp(move, "rra") == 0)
		reverse_rotate(&data->a);
	else if (ft_strcmp(move, "rrb") == 0)
		reverse_rotate(&data->b);
	else if (ft_strcmp(move, "rrr") == 0)
		reverse_rotate_both(&data->a, &data->b);
	else
		error_move(data, move);
}

static void	run_get_next_line(t_data *data)
{
	char	*move;

	while (get_next_line(STDIN_FILENO, &move))
	{
		check_move(data, move);
		free(move);
	}
	free(move);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		error_exit();
	data = set_data(data, argv);
	if (data->size > 1)
	{
		if (check_double(data->a) == 1)
			error_free(data);
		run_get_next_line(data);
		if (check_sorted(data->a) == 0 && data->b == NULL)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		ft_putstr_fd("OK\n", 1);
	final_free(data);
	return (0);
}
