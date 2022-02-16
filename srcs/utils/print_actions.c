/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:29:12 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/10 11:29:13 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action(t_actions action)
{
	if (action == SWAP_A)
		ft_putstr_fd("sa\n", 1);
	if (action == SWAP_B)
		ft_putstr_fd("sb\n", 1);
	if (action == SWAP_A_B)
		ft_putstr_fd("ss\n", 1);
	if (action == PUSH_A)
		ft_putstr_fd("pa\n", 1);
	if (action == PUSH_B)
		ft_putstr_fd("pb\n", 1);
	if (action == ROTATE_A)
		ft_putstr_fd("ra\n", 1);
	if (action == ROTATE_B)
		ft_putstr_fd("rb\n", 1);
	if (action == ROTATE_A_B)
		ft_putstr_fd("rr\n", 1);
	if (action == REVERSE_ROTATE_A)
		ft_putstr_fd("rra\n", 1);
	if (action == REVERSE_ROTATE_B)
		ft_putstr_fd("rrb\n", 1);
	if (action == REVERSE_ROTATE_A_B)
		ft_putstr_fd("rrr\n", 1);
}
