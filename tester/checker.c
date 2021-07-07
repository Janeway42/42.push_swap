/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/30 13:23:05 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/07 12:22:44 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static void	check_move(t_data *data, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		swap(&data->a);
	else if (ft_strcmp(move, "sb\n") == 0)
		swap(&data->b);
	else if (ft_strcmp(move, "ss\n") == 0)
		swap_both(&data->a, &data->b);
	else if (ft_strcmp(move, "pa\n") == 0)
		push(&data->a, &data->b);
	else if (ft_strcmp(move, "pb\n") == 0)
		push(&data->b, &data->a);
	else if (ft_strcmp(move, "ra\n") == 0)
		rotate(&data->a);
	else if (ft_strcmp(move, "rb\n") == 0)
		rotate(&data->b);
	else if (ft_strcmp(move, "rr\n") == 0)
		rotate_both(&data->a, &data->b);
	else if (ft_strcmp(move, "rra\n") == 0)
		reverse_rotate(&data->a);
	else if (ft_strcmp(move, "rrb\n") == 0)
		reverse_rotate(&data->b);
	else if (ft_strcmp(move, "rrr\n") == 0)
		reverse_rotate_both(&data->a, &data->b);
	else
		error_exit();
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	*move;

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
	free(move);
	if (check_sorted(data->a) == 0 && data->b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd ("KO\n", 1);
	free_exit (data);
	return (0);
}
