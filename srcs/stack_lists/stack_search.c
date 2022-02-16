/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:14:37 by osurcouf          #+#    #+#             */
/*   Updated: 2021/09/22 20:14:39 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min_value(t_stack *stack)
{
	int	minimum;

	minimum = stack->nb;
	while (stack)
	{
		if (stack->nb < minimum)
			minimum = stack->nb;
		stack = stack->next;
	}
	return (minimum);
}

int	stack_max_value(t_stack *stack)
{
	int	maximum;

	maximum = stack->nb;
	while (stack)
	{
		if (stack->nb > maximum)
			maximum = stack->nb;
		stack = stack->next;
	}
	return (maximum);
}

int	find_position_of_nb(t_stack *stack, int position)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == position)
			return (stack->nb);
		stack = stack->next;
		i++;
	}
	return (INT_MIN);
}

int	find_nb_at_position(t_stack *stack, int max)
{
	int	count;

	count = 0;
	while (stack && stack->nb != max)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
