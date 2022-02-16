/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity_checks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:28:24 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/09 13:28:25 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	input_is_number(char *argv)
{
	size_t	i;

	i = 0;
	if (i < ft_strlen(argv) && (argv[i] == '+' || argv[i] == '-'))
		i++;
	while (i < ft_strlen(argv))
	{
		if (!ft_isdigit(argv[i]))
			error(NOT_NUMBER, NULL, NULL);
		i++;
	}	
	if (ft_atof(argv) > INT_MAX)
		error(OVER_MAX, NULL, NULL);
	if (ft_atof(argv) < INT_MIN)
		error(OVER_MIN, NULL, NULL);
	return (true);
}

bool	there_is_duplicate(t_stack **stack)
{
	t_stack	*comparing;
	t_stack	*compared;

	comparing = *stack;
	while (comparing)
	{
		compared = comparing->next;
		while (compared)
		{
			if (comparing->nb == compared->nb)
				return (true);
			compared = compared->next;
		}
		comparing = comparing->next;
	}
	return (false);
}

bool	stack_is_sorted(t_stack **stack)
{
	t_stack	*comparing;
	t_stack	*compared;

	comparing = *stack;
	compared = comparing->next;
	while (comparing && compared)
	{
		if (comparing->nb > compared->nb)
			return (false);
		comparing = comparing->next;
		compared = compared->next;
	}
	return (true);
}
