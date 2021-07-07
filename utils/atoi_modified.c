/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_modified.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: janeway <janeway@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 11:50:32 by janeway       #+#    #+#                 */
/*   Updated: 2021/07/06 16:47:30 by janeway       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	ft_compare(char i)
{
	if (i == ' '
		|| i == '\n'
		|| i == '\t'
		|| i == '\v'
		|| i == '\f'
		|| i == '\r')
		return (1);
	return (0);
}

static int	atoi_overflow(unsigned long value, int sign, t_data *c)
{
	if (value >= (LONG_MAX - 1) && sign == 1)
	{
		c->int_max = 1;
		return (-1);
	}
	if (value >= (LONG_MAX - 1) && sign == -1)
	{
		c->int_max = -1;
		return (0);
	}
	else
		return ((int)(value * sign));
}

int	ft_atoi(const char *nptr, t_data *c)
{
	int				i;
	int				sign;
	unsigned long	value;

	i = 0;
	sign = 1;
	value = 0;
	if (!*nptr)
		return (0);
	while (ft_compare(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = value * 10 + (nptr[i] - '0');
		i++;
	}
	return (atoi_overflow(value, sign, c));
}
