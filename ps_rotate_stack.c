/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:49:52 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/12 16:26:14 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void rotate_one(t_list **stack, int *index, char which)
// {
// 	while (*index > 0)
// 	{
// 		if (which == 'a')
// 			ra(stack);
// 		else
// 			rb(stack);
// 		(*index)--;
// 	}
// 	while (*index < 0)
// 	{
// 		if (which == 'a')
// 			rra(stack);
// 		else
// 			rrb(stack);
// 		(*index)++;
// 	}
// }

// static void rotate_both(t_list **a, t_list **b, int *index_a, int *index_b)
// {
// 	while (*index_a > 0 && *index_b > 0)
// 	{
// 		rr(a, b);
// 		(*index_a)--;
// 		(*index_b)--;
// 	}
// 	while (*index_a < 0 && *index_b < 0)
// 	{
// 		rrr(a, b);
// 		(*index_a)++;
// 		(*index_b)++;
// 	}
// }

// void number_up(t_list **a, t_list **b, int index_a, int index_b)
// {
// 	rotate_both(a, b, &index_a, &index_b);
// 	rotate_one(a, &index_a, 'a');
// 	rotate_one(b, &index_b, 'b');
// }

void	number_up(t_list **a, t_list **b, int index_a, int index_b)
{
	while (index_a > 0 && index_b > 0)
	{
		rr(a, b);
		index_a--;
		index_b--;
	}
	while (index_a < 0 && index_b < 0)
	{
		rrr(a, b);
		index_a++;
		index_b++;
	}
	while (index_a > 0)
	{
		ra(a);
		index_a--;
	}
	while (index_a < 0)
	{
		rra(a);
		index_a++;
	}
	while (index_b > 0)
	{
		rb(b);
		index_b--;
	}
	while (index_b < 0)
	{
		rrb(b);
		index_b++;
	}
}
