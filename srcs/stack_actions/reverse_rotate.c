/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:46:31 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 10:46:32 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	reverse_rotate(t_stack **stack)
{
	t_stack	*element_to_reverse_rotate;

	if (stack_size(*stack) < 2)
		return (false);
	element_to_reverse_rotate = stack_last(*stack);
	stack_add_front(stack, element_to_reverse_rotate);
	while (*stack)
	{
		if ((*stack)->next == element_to_reverse_rotate)
			(*stack)->next = NULL;
		*stack = (*stack)->next;
	}
	*stack = element_to_reverse_rotate;
	return (true);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		print_action(REVERSE_ROTATE_A);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (reverse_rotate(stack_b))
		print_action(REVERSE_ROTATE_B);
}

void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		print_action(REVERSE_ROTATE_A_B);
	else if (reverse_rotate(stack_a))
		print_action(REVERSE_ROTATE_A);
	else if (reverse_rotate(stack_b))
		print_action(REVERSE_ROTATE_B);
}	
