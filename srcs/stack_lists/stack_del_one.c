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
** function : lstdelone
** This function deletes the memory of one list.
** 🦕
*/

#include "push_swap.h"

void	stack_del_one(t_stack *stack)
{
	stack->next = NULL;
	free(stack);
}
