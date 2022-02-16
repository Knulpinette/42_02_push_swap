/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_version.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:34:25 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 18:34:26 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(
	t_stack **stack_a, t_stack **stack_b, t_stack **limits, int index)
{
	if (stack_size(*limits) == 1)
		return ;
	if (stack_size(*limits) == 2 && count_in_between_limits(
			*stack_a, (*limits)->nb, (*limits)->next->nb) >= MAX_SIZE_STACK_B)
		get_new_limit(stack_a, limits);
	if (!stack_size(*stack_b))
		push_lower_half_to_b(stack_a, stack_b, limits, index);
	else if (stack_size(*stack_b) >= MAX_SIZE_STACK_B)
		push_higher_half_back_to_a(stack_a, stack_b, limits);
	else
	{
		push_back_to_a_until_sorted(stack_a, stack_b);
		remove_first_list(limits);
	}
	index++;
	sort_big_stack(stack_a, stack_b, limits, index);
}

void	push_lower_half_to_b(
	t_stack **stack_a, t_stack **stack_b, t_stack **limits, int index)
{
	int	half_stack;
	int	first_limit;
	int	second_limit;

	first_limit = (*limits)->nb;
	second_limit = (*limits)->next->nb;
	half_stack = count_in_between_limits(*stack_a, first_limit, second_limit);
	if (index == 0)
		half_stack++;
	while (half_stack)
	{
		first_limit = (*limits)->nb;
		second_limit = (*limits)->next->nb;
		if ((*stack_a)->nb >= first_limit && (*stack_a)->nb <= second_limit)
		{
			do_action(PUSH_B, stack_a, stack_b);
			half_stack--;
		}
		else
			do_action(ROTATE_A, stack_a, stack_b);
	}
}

void	push_higher_half_back_to_a(
	t_stack **stack_a, t_stack **stack_b, t_stack **limits)
{
	int	half_stack;

	get_new_limit(stack_b, limits);
	half_stack = count_in_between_limits(
			*stack_b, (*limits)->next->nb, (*limits)->next->next->nb);
	while (half_stack)
	{
		if ((*stack_b)->nb > (*limits)->next->nb)
		{
			do_action(PUSH_A, stack_a, stack_b);
			half_stack--;
		}
		else
			do_action(ROTATE_B, stack_a, stack_b);
	}
}

void	push_back_to_a_until_sorted(
	t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		if ((*stack_b)->nb == stack_min_value(*stack_b))
		{
			do_action(PUSH_A, stack_a, stack_b);
			do_action(ROTATE_A, stack_a, stack_b);
		}
		else
		{
			push_value(MAXIMUM, PUSH_A, stack_a, stack_b);
			if (*stack_b && (*stack_b)->nb != stack_max_value(*stack_b))
				do_action(ROTATE_A_B, stack_a, stack_b);
			else
				do_action(ROTATE_A, stack_a, stack_b);
		}
	}
}
