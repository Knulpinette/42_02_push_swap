/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:14:41 by osurcouf          #+#    #+#             */
/*   Updated: 2021/02/22 15:14:43 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 🦕
** function : lstnew
** This function creates a new list and allocates memory for it.
** 🦕
*/

#include "push_swap.h"

t_stack	*stack_new(int nb)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->nb = nb;
	stack->next = NULL;
	return (stack);
}
