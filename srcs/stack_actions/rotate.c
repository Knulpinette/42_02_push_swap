/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:46:36 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 10:46:38 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate(t_stack **stack)
{
	t_stack	*element_to_rotate;

	if (stack_size(*stack) < 2)
		return (false);
	element_to_rotate = *stack;
	*stack = (*stack)->next;
	stack_add_back(stack, element_to_rotate);
	element_to_rotate->next = NULL;
	return (true);
}

void	rotate_a(t_stack **stack_a)
{
	if (rotate(stack_a))
		print_action(ROTATE_A);
}

void	rotate_b(t_stack **stack_b)
{
	if (rotate(stack_b))
		print_action(ROTATE_B);
}

void	rotate_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		print_action(ROTATE_A_B);
	else if (rotate(stack_a))
		print_action(ROTATE_A);
	else if (rotate(stack_b))
		print_action(ROTATE_B);
}
