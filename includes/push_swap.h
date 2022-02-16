/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:06:42 by osurcouf          #+#    #+#             */
/*   Updated: 2021/08/04 14:06:44 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "colors.h"
# include "../libft/libft.h"

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/*                                 Algorithm                                  */
/* ************************************************************************** */

typedef enum e_values
{
	MAXIMUM,
	MINIMUM,
}	t_values;

# define MAX_SIZE_STACK_B 20

void	sort_stack(int argc, t_stack **stack_a, t_stack **stack_b);
void	sort_little_stack(
			int argc, t_stack **stack_a, t_stack **stack_b, t_stack *limits);
void	sort_big_stack(
			t_stack **stack_a, t_stack **stack_b, t_stack **limits, int index);

/* ************************************************************************** */
/*                         Stack actions functions                            */
/* ************************************************************************** */

typedef enum e_actions
{
	SWAP_A = 1,
	SWAP_B,
	SWAP_A_B,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_A_B,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_A_B,
}	t_actions;

void	do_action(t_actions action, t_stack **stack_a, t_stack **stack_b);
/* swap */
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_a_b(t_stack **stack_a, t_stack **stack_b);
/* push*/
void	push_a(t_stack **stack_b, t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);
/* rotate */
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_a);
void	rotate_a_b(t_stack **stack_a, t_stack **stack_b);
/* reverse rotate */
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_b(t_stack **stack_a, t_stack **stack_b);

/* ************************************************************************** */
/*                         Stack lists functions                              */
/* ************************************************************************** */

void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
t_stack	*stack_copy(t_stack *stack);
void	stack_del_one(t_stack *stack);
void	remove_first_list(t_stack **stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int nb);
int		stack_size(t_stack *stack);
void	stack_sort(t_stack **stack);
t_stack	*merge_sort(t_stack *left, t_stack *right);
t_stack	*stack_split(t_stack *stack);
int		stack_min_value(t_stack *stack);
int		stack_max_value(t_stack *stack);
void	print_stack(t_stack **stack);
void	free_the_stacks(t_stack **stack_a, t_stack **stack_b);
int		find_position_of_nb(t_stack *stack, int position);
int		find_nb_at_position(t_stack *stack, int max);

/* ************************************************************************** */
/*                                Utilities                                   */
/* ************************************************************************** */

/* Algorithm utils */

t_stack	*initialize_limits(t_stack **stack_a);
void	get_new_limit(t_stack **stack, t_stack **limits);
int		get_median(t_stack *stack);
int		count_in_between_limits(t_stack *stack, int min, int max);
void	push_value(
			int value, t_actions action, t_stack **stack_a, t_stack **stack_b);
void	push_lower_half_to_b(
			t_stack **stack_a, t_stack **stack_b, t_stack **limits, int index);
void	push_higher_half_back_to_a(
			t_stack **stack_a, t_stack **stack_b, t_stack **limits);
void	push_back_to_a_until_sorted(t_stack **stack_a, t_stack **stack_b);

/* Print actions */

void	print_action(t_actions action);

/* Building the stacks */

void	initialize_stack_a(int argc, char **argv, t_stack **stack_a);
void	build_stack(t_stack **stack, int nb);

/* Input validity checks */

bool	input_is_number(char *argv);
bool	there_is_duplicate(t_stack **stack);
bool	stack_is_sorted(t_stack **stack);

/* Error handling */

typedef enum e_error
{
	ERROR,
	NOT_NUMBER,
	DUPLICATE,
	OVER_MAX,
	OVER_MIN,
	MEMORY_ALLOC,
	SORTED,
}	t_error;

int		error(t_error error, t_stack **stack_a, t_stack **stack_b);
void	error_message(t_error error);

#endif