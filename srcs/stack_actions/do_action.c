/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 12:41:11 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/18 12:41:12 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_action(t_actions action, t_stack **stack_a, t_stack **stack_b)
{
	if (action == SWAP_A)
		swap_a(stack_a);
	else if (action == SWAP_B)
		swap_b(stack_b);
	else if (action == SWAP_A_B)
		swap_a_b(stack_a, stack_b);
	else if (action == PUSH_A)
		push_a(stack_b, stack_a);
	else if (action == PUSH_B)
		push_b(stack_a, stack_b);
	else if (action == ROTATE_A)
		rotate_a(stack_a);
	else if (action == ROTATE_B)
		rotate_b(stack_b);
	else if (action == ROTATE_A_B)
		rotate_a_b(stack_a, stack_b);
	else if (action == REVERSE_ROTATE_A)
		reverse_rotate_a(stack_a);
	else if (action == REVERSE_ROTATE_B)
		reverse_rotate_b(stack_b);
	else if (action == REVERSE_ROTATE_A_B)
		reverse_rotate_a_b(stack_a, stack_b);
}
