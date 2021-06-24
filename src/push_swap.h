/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 15:58:16 by janeway       #+#    #+#                 */
/*   Updated: 2021/06/21 18:36:29 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
		struct s_stack *next;
		int val;
		int index;
		struct s_stack *prev;
}				t_stack;

typedef struct s_data
{
	struct	s_stack *a;
	struct	s_stack *b;
	char	**argv;
	int		int_max;
	int		half;
	int		sort;
}				t_data;

/*
** set data
*/

t_data	*set_data(t_data *data, char **argv);
void	check_digit(char *str);
int		check_sorted(t_stack *x);
int		check_double(t_stack *x);


/*
** sorting
*/

void	move_elem(t_data *data, t_stack **x, int number);
void	move_elem_return_b(t_data *data, t_stack **x, int number);
void	sort_upto_five(t_data *data, int size);
void	sort_upto_hundred(t_data *data, int size);


/*
** moves
*/

void	swap(t_stack **x);
void	push(t_stack **dest, t_stack **src);
void	rotate(t_stack **x);
void	reverse_rotate(t_stack **x);

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

void	error_exit();
void	error_int_max(t_data *data);

/*
** presort
*/

void	presort_stack(t_data *data);

/*
** ERASE
*/

void print_stack (t_stack *x);


#endif