/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubbly_sort_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:05:29 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/27 12:22:44 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Efficiently sorts very small sets by using bubble sort on Stack A, unless the
** item at the top of stack A is the smallest item in stack A. In that case the
** item is pushed to stack B. Stack B will always be reverse sorted and only
** contain the smallest items. When stack A is sorted and the smallest item is
** on top, Stack B's contents are pushed back, and the sorting is complete.
*/

void			bubbly_sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker)
{
	int		*tmp_arr;
	int		sm;
	int		sl;

	while (!is_sorted(*sa))
	{
		sl = stack_length(*sa);
		sm = tmp_arr[ft_smallest_int(create_a_value_array(*sa, &tmp_arr), sl)];
		free(tmp_arr);
		if (sm == (*sa)->value)
		{
			execute_instruction(sa, sb, tracker, PB);
			sl = stack_length(*sa);
		}
		else if ((*sa)->value > (*sa)->next->value)
			execute_instruction(sa, sb, tracker, SA);
		else
			execute_instruction(sa, sb, tracker, RA);
		if (ft_ints_are_sorted(create_a_value_array(*sa, &tmp_arr), sl))
			rotate_smallest_to_top(sa, sb, tracker);
		free(tmp_arr);
	}
	while (*sb)
		execute_instruction(sa, sb, tracker, PA);
}

/*
** Returns  an array of ints from stack a which is sorted smallest to largest.
*/

int				*create_a_value_array(t_swap *stack, int **a_val_arr)
{
	int		i;
	int		stack_len;
	int		*tmp_arr;

	stack_len = stack_length(stack);
	if (!(tmp_arr = (int *)malloc(sizeof(int) * stack_len)))
		return (NULL);
	ft_bzero(tmp_arr, sizeof(int) * stack_len);
	i = 0;
	while (stack)
	{
		tmp_arr[i++] = stack->value;
		stack = stack->next;
	}
	*a_val_arr = ft_int_sort(tmp_arr, stack_len);
	free(tmp_arr);
	return (*a_val_arr);
}
