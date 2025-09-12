/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:59:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/12 16:38:48 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **a)
{
	if ((*a)->index == 0 && (*a)->next->index == 2)
	{
		rra(a);
		sa(a);
	}
	else if ((*a)->index == 1)
	{
		if ((*a)->next->index == 0)
			sa(a);
		else
			rra(a);
	}
	else if ((*a)->index == 2)
	{
		if ((*a)->next->index == 0)
			rra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

int	index_find_b(t_list *b, int a_index)
{
	int		pos;
	int		best_pos;
	int		best_diff;
	t_list	*node;

	pos = 0;
	best_pos = 0;
	best_diff = 2147483647;
	node = b;
	while (node)
	{
		if (node->index > a_index && node->index - a_index < best_diff)
		{
			best_diff = node->index - a_index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	if (best_diff == 2147483647)
		best_pos = 0;
	return (best_pos);
}

int	step_count(int index_a, int index_b)
{
	int	step;

	step = 0;
	if (index_a < 0 && index_b < 0)
	{
		if (index_a < index_b)
			step = -index_a;
		else
			step = -index_b;
	}
	else if (index_a >= 0 && index_b >= 0)
	{
		if (index_a > index_b)
			step = index_a;
		else
			step = index_b;
	}
	else if (index_a > 0 && index_b < 0)
		step = index_a + (-index_b);
	else if (index_a < 0 && index_b > 0)
		step = (-index_a) + index_b;
	return (step);
}
int	find_min_index(t_list *a, t_list *b)
{
	t_list	*node;
	int		min_step;
	int		min_pos;
	int		pos_a;
	int		size_a;
	int		size_b;

	node = a;
	min_step = -1;
	min_pos = 0;
	pos_a = 0;
	size_a = list_size(a);
	size_b = list_size(b);
	while (node)
	{
		int b_pos = index_find_b(b, node->index);
		int index_a = pos_to_index(pos_a, size_a);
		int index_b = pos_to_index(b_pos, size_b);
		int step = step_count(index_a, index_b);
		if (min_step == -1 || step < min_step)
		{
			min_step = step;
			min_pos = pos_a; // burada pozisyonu saklıyoruz
		}
		node = node->next;
		pos_a++;
	}
	return (min_pos);
}




