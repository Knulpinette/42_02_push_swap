/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:14:52 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:14:53 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : lstsize
** This function returns the number of elements in a given linked list.
** 🦕
*/

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_stack	*index;
	int		size;

	if (!stack)
		return (0);
	index = stack;
	size = 1;
	while (index->next != 0)
	{
		index = index->next;
		size++;
	}
	return (size);
}
