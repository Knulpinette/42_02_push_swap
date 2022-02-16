/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:54:59 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/26 13:55:00 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_limits(t_stack **stack_a)
{
	int		min;
	int		max;
	t_stack	*limits;

	min = stack_min_value(*stack_a);
	max = stack_max_value(*stack_a);
	limits = stack_new(min);
	stack_add_back(&limits, stack_new(max));
	return (limits);
}

void	get_new_limit(t_stack **stack, t_stack **limits)
{
	int		median;
	t_stack	*new_limit;

	median = get_median(*stack);
	new_limit = stack_new(median);
	if (new_limit->nb <= (*limits)->nb)
	{
		stack_del_one(new_limit);
		return ;
	}
	stack_add_front(limits, new_limit);
	if (there_is_duplicate(limits))
		remove_first_list(limits);
	else
		stack_sort(limits);
}

int	get_median(t_stack *stack)
{
	t_stack	*duplicate;
	int		stack_half;
	int		median;

	duplicate = stack_copy(stack);
	stack_half = stack_size(duplicate) / 2;
	stack_sort(&duplicate);
	median = find_position_of_nb(duplicate, stack_half);
	stack_clear(&duplicate);
	return (median);
}

int	count_in_between_limits(t_stack *stack, int min, int max)
{
	int		index_min;
	int		index_max;
	int		count;
	t_stack	*duplicate;

	count = 0;
	duplicate = stack_copy(stack);
	stack_sort(&duplicate);
	index_min = find_nb_at_position(duplicate, min);
	index_max = find_nb_at_position(duplicate, max);
	count = index_max - index_min;
	stack_clear(&duplicate);
	return (count);
}
