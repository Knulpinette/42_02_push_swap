/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:07:27 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 12:07:28 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*print;

	if (!*stack)
		return ;
	print = *stack;
	while (print)
	{
		ft_putnbr_fd(print->nb, 1);
		ft_putchar_fd('\n', 1);
		print = print->next;
	}
}
