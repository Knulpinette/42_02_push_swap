/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:59:51 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/04 13:59:52 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		return (input_is_number(argv[1]));
	stack_a = NULL;
	stack_b = NULL;
	initialize_stack_a(argc, argv, &stack_a);
	if (!stack_is_sorted(&stack_a))
		sort_stack(argc - 1, &stack_a, &stack_b);
	free_the_stacks(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

void	sort_stack(int argc, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*limits;

	limits = initialize_limits(stack_a);
	if (argc <= 5)
		sort_little_stack(argc, stack_a, stack_b, limits);
	else
		sort_big_stack(stack_a, stack_b, &limits, 0);
	stack_clear(&limits);
}
