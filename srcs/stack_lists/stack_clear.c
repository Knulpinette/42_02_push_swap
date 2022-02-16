/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:13:53 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:13:55 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : lstclear
** This function cleans the memory of a whole given chained linked list.
** Then sets the first pointer to the list to NULL.
** 🦕
*/

#include "push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*index;
	t_stack	*temp;

	if (!*stack)
		return ;
	index = *stack;
	while (index)
	{
		temp = index->next;
		stack_del_one(index);
		index = temp;
	}
	*stack = NULL;
}
