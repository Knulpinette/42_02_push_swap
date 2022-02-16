/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:14:16 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:14:19 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : lstlast
** This function return a pointer to the last element of a linked list.
** 🦕
*/

#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next != 0)
		last = last->next;
	return (last);
}
