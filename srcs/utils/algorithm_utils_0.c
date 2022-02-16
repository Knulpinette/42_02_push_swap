/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_specific_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:48:34 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/19 12:48:36 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** action = PUSH_A or PUSH_B
** value = MAXIMUM or MINIMUM
*/

static t_stack	**initialize_values(
	int action, t_stack **stack, int *rev_rotate, int *rotate)
{
	if (action == PUSH_B)
	{
		*rev_rotate = REVERSE_ROTATE_A;
		*rotate = ROTATE_A;
		return (stack);
	}
	else
	{
		*rev_rotate = REVERSE_ROTATE_B;
		*rotate = ROTATE_B;
		return (stack);
	}
}

static bool	value_is_after_half(int value, int half_of_stack, t_stack *stack)
{
	int	index;

	index = 0;
	while (index <= half_of_stack)
	{
		if (stack->nb == value)
			return (false);
		stack = stack->next;
		index++;
	}
	return (true);
}

void	push_value(
	int value, t_actions action, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	**stack;
	int		reverse_rotate;
	int		rotate;
	int		half;

	if (action == PUSH_B)
		stack = initialize_values(action, stack_a, &reverse_rotate, &rotate);
	else
		stack = initialize_values(action, stack_b, &reverse_rotate, &rotate);
	if (value == MAXIMUM)
		value = stack_min_value(*stack);
	else if (value == MINIMUM)
		value = stack_min_value(*stack);
	half = stack_size(*stack) / 2;
	while ((*stack)->nb != value)
	{
		if (((*stack)->nb != value && (*stack)->next->nb != value)
			|| value_is_after_half(value, half, *stack))
			do_action(reverse_rotate, stack_a, stack_b);
		else
			do_action(rotate, stack_a, stack_b);
	}
	do_action (action, stack_a, stack_b);
}
