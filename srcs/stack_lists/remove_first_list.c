/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:14:06 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:14:08 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : remove first list
** This function deletes the memory of the first list and
** makes sure the pointers now directs towards the new first one.
** 🦕
*/

#include "push_swap.h"

void	remove_first_list(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	(*stack)->next = NULL;
	free(*stack);
	*stack = temp;
}
