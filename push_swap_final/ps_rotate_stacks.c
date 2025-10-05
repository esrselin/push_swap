/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:59:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/02 17:44:58 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	if (size <= 10)
		return (1);
	if (size <= 100)
		return (5);
	return (11);
}

void	rotate_to_top_a(t_list **a, int pos)
{
	int		size;

	if (!a || !*a || pos <= 0)
		return ;
	size = list_size(*a);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(a);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(a);
	}
}

static void	rotate_to_top_b(t_list **b, int pos)
{
	int		size;

	if (!b || !*b || pos <= 0)
		return ;
	size = list_size(*b);
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(b);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

void	push_back_max(t_list **b, t_list **a)
{
	int		pos;

	while (*b)
	{
		pos = max_index_pos(*b, NULL);
		rotate_to_top_b(b, pos);
		pa(a, b);
	}
}
