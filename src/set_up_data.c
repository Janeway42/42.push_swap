/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_up_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 16:05:56 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/24 10:54:24 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_double(t_stack *x)
{
	t_stack *compared;
	t_stack *temp;
	
	compared = x;
	while (compared != NULL)
	{
		temp = compared->next;
		while (temp != NULL)
		{
			if ((compared->val) == (temp->val))
				return (1);
			else
				temp = temp->next;
		}
		compared = compared->next;
	}
	return (0);
}

int check_sorted(t_stack *x)
{
	t_stack *temp;

	temp = x;
	while (temp->next != NULL)
	{
		if (temp->val > (temp->next)->val)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void fill_a(t_data *data)
{
	t_stack	*new;
	char	*str;
	int		num;

	data->argv++;
	while (*(data->argv))
	{
		str = *(data->argv);
		check_digit(str);
		num = ft_atoi(str, data);
		if (data->int_max == 1)
			error_int_max(data);
		new = create_new_elem(num);
//		printf("%d\n", new->val);
		if (!new)
		{
			// free data? free stack? free element? 
			exit (1);
		}			
		add_at_the_end(&data->a, new);
//		print_stack(data->a);
		data->argv++;
	}
}

static t_data *set_struct(t_data *data, char **argv)
{

	data->a = NULL;
	data->b = NULL;
	data->argv = argv;
	data->int_max = 0;
	data->int_max = 0;
	data->half = 0;
	data->sort = 1;
	return (data);
}

t_data *set_data(t_data *data, char **argv)
{
	data = set_struct(data, argv);
	fill_a(data);
	if (check_sorted(data->a) == 0 || check_double(data->a) == 1)
		{
			free(data); // data - stack 
//			printf("Already sorted\n");  // erase
			exit(1);
		}
	return (data);
}