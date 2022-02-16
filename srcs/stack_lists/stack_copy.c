/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:33:11 by osurcouf          #+#    #+#             */
/*   Updated: 2021/09/21 11:33:14 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_copy(t_stack *stack)
{
	t_stack	*copy;
	t_stack	*new_element;

	copy = NULL;
	while (stack)
	{
		new_element = stack_new(stack->nb);
		if (!new_element)
		{
			stack_clear(&copy);
			return (NULL);
		}
		stack_add_back(&copy, new_element);
		stack = stack->next;
	}
	return (copy);
}
