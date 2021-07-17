/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:58:16 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/17 19:38:59 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				val;
	int				index;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	char			**argv;
	int				int_max;
	int				min;
	int				max;
	int				half;
	int				sort;
	int				size;
	int				block;
	int				nr_blocks;
	int				remainder;
}				t_data;

/*
** set data
*/

t_data	*set_data(t_data *data, char **argv);
t_data	*set_struct(t_data *data, char **argv);
void	fill_a(t_data *data);
void	check_digit(t_data *data, char *str);
int		check_sorted(t_stack *x);
int		check_sorted_reversed(t_stack *x);
int		check_double(t_stack *x);
void	check_data(t_data *data);

/*
** sorting
*/

void	move_elem_a(t_stack **x, int number);
void	move_elem_b(t_stack **x, int number);
void	move_elem_return_b(t_data *data, t_stack **x, int number);
void	sort_upto_five(t_data *data);
void	sort_more_than_five(t_data *data);
void	b_larger_than_last(t_data *data, t_stack *temp, t_stack *last);
void	last_larger_than_b(t_data *data, t_stack *temp, t_stack *last);

/*
** presort
*/

void	presort_stack(t_data *data);

/*
** moves
*/

void	swap(t_stack **x);
void	swap_both(t_stack **a, t_stack **b);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **x);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **x);
void	reverse_rotate_both(t_stack **a, t_stack **b);

void	write_sa(t_stack **a);
void	write_sb(t_stack **b);
void	write_ss(t_stack **a, t_stack **b);

void	write_pa(t_stack **a, t_stack **b);
void	write_pb(t_stack **a, t_stack **b);

void	write_ra(t_stack **a);
void	write_rb(t_stack **b);
void	write_rr(t_stack **a, t_stack **b);

void	write_rra(t_stack **a);
void	write_rrb(t_stack **b);
void	write_rrr(t_stack **a, t_stack **b);

/*
** utils linked lists
*/

int		ft_atoi(const char *nptr, t_data *c);
int		iterate(t_stack *x);
t_stack	*create_new_elem(int number);
void	add_at_the_end(t_stack **x, t_stack *element);
int		find_position(t_stack *x, int number);
int		find_min(t_stack *x);
int		find_max(t_stack *x);

/*
** free and error
*/

void	free_stack(t_stack **x);
void	error_exit(void);
void	error_free(t_data *data);
void	free_exit(t_data *data);
void	final_free(t_data *data);

#endif
