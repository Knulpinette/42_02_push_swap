/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:39:40 by osurcouf          #+#    #+#             */
/*   Updated: 2021/09/21 10:39:42 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_sort(t_stack **stack)
{
	t_stack	*left;
	t_stack	*right;

	left = *stack;
	if (!left || !left->next)
		return ;
	right = stack_split(left);
	stack_sort(&left);
	stack_sort(&right);
	*stack = merge_sort(left, right);
}

t_stack	*merge_sort(t_stack *left, t_stack *right)
{
	t_stack	*merged_stack;

	merged_stack = NULL;
	if (!left)
		return (right);
	if (!right)
		return (left);
	if (left->nb < right->nb)
	{
		merged_stack = left;
		merged_stack->next = merge_sort(left->next, right);
	}
	else
	{
		merged_stack = right;
		merged_stack->next = merge_sort(left, right->next);
	}
	return (merged_stack);
}

t_stack	*stack_split(t_stack *stack)
{
	t_stack	*slow;
	t_stack	*fast;
	t_stack	*middle_stack;

	slow = stack;
	fast = stack;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	middle_stack = slow->next;
	slow->next = 0;
	return (middle_stack);
}
