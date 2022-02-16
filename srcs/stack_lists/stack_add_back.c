/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:13:31 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:13:36 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : lstadd_back
** This function add a new given list to the end of a given linked list.
** 🦕
*/

#include "push_swap.h"

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
		stack_add_front(stack, new);
	else
	{
		last = stack_last(*stack);
		last->next = new;
	}
}
