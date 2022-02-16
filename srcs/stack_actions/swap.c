/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:46:17 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 10:46:18 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_stack **stack)
{
	t_stack	*second_stack_element;
	t_stack	*third_stack_element;

	if (stack_size(*stack) < 2)
		return (false);
	second_stack_element = (*stack)->next;
	third_stack_element = (*stack)->next->next;
	stack_add_front(stack, second_stack_element);
	(*stack)->next->next = third_stack_element;
	return (true);
}

void	swap_a(t_stack **stack_a)
{
	if (swap(stack_a))
		print_action(SWAP_A);
}

void	swap_b(t_stack **stack_b)
{
	if (swap(stack_b))
		print_action(SWAP_B);
}

void	swap_a_b(t_stack **stack_a, t_stack **stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		print_action(SWAP_A_B);
	else if (swap(stack_a))
		print_action(SWAP_A);
	else if (swap(stack_b))
		print_action(SWAP_B);
}
