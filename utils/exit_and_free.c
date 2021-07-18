/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_and_free.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:46:43 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/18 11:14:22 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	free_stack(t_stack **x)
{
	t_stack	*temp;

	temp = *x;
	while (*x != NULL)
	{
		temp = *x;
		*x = (*x)->next;
		free(temp);
		temp = NULL;
	}
}

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	error_free_exit(t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(&data->a);
	free(data);
	exit(1);
}

void	free_exit(t_data *data)
{
	free_stack(&data->a);
	free(data);
	exit(0);
}

void	final_free(t_data *data)
{
	free_stack(&data->a);
	free_stack(&data->b);
	free(data);
}
