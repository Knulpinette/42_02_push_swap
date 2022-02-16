/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:30:47 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/09 13:30:48 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_error error, t_stack **stack_a, t_stack **stack_b)
{
	free_the_stacks(stack_a, stack_b);
	error_message(error);
	exit(EXIT_FAILURE);
}

void	error_message(t_error error)
{
	ft_putstr_fd(""LIGHT_RED"Error\n"END_COLOR"", 1);
	if (error == NOT_NUMBER)
		ft_putstr_fd("One of the arguments is not an int.\n", 1);
	else if (error == OVER_MAX)
		ft_putstr_fd("One of the argument is over the INT_MAX.\n", 1);
	else if (error == OVER_MIN)
		ft_putstr_fd("One of the arguments is under the INT_MIN.\n", 1);
	else if (error == MEMORY_ALLOC)
		ft_putstr_fd("Memory badly allocated !\n", 1);
	else if (error == DUPLICATE)
		ft_putstr_fd("There's a duplicate number in your input.\n", 1);
}
