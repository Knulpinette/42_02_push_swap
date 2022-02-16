/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_the_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:39:22 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 10:39:23 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_the_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a)
		stack_clear(stack_a);
	if (stack_b)
		stack_clear(stack_b);
}
