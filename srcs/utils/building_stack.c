/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:29:39 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/09 13:29:40 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack_a(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (input_is_number(argv[i]))
			build_stack(stack_a, ft_atoi(argv[i]));
		i--;
	}
	if (there_is_duplicate(stack_a))
		error(DUPLICATE, stack_a, NULL);
}

void	build_stack(t_stack **stack, int nb)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = stack_new(nb);
		if (*stack == NULL)
			error(MEMORY_ALLOC, stack, NULL);
	}
	else
	{
		temp = stack_new(nb);
		if (temp == NULL)
			error(MEMORY_ALLOC, stack, NULL);
		stack_add_front(stack, temp);
	}
}
