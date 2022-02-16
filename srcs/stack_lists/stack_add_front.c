/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:13:42 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:13:46 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : lstadd_front
** This function add a new given list to the beginning of a given linked list.
** 🦕
*/

#include "push_swap.h"

void	stack_add_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
	return ;
}
