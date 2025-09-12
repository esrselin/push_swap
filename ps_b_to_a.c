/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:52:24 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/12 10:51:05 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_to_b(t_list **a, t_list **b)
{
	int		a_size;
	int		target_index;
	int		index_a;
	int		index_b;
	t_list	*tmp;
	int		pos_a;

	a_size = list_size(*a);
	while (a_size > 3)
	{
		target_index = find_min_index(*a, *b);
		pos_a = 0;
		tmp = *a;
		while (tmp && tmp->index != target_index)
		{
			tmp = tmp->next;
			pos_a++;
		}
		index_a = pos_to_index(pos_a, a_size);
		index_b = pos_to_index(index_find_b(*b, target_index), list_size(*b));
		number_up(a, b, index_a, index_b);
		pb(a, b);
		a_size--;
	}
	ft_sort_3(a);
}
int	find_b_max(t_list *b)
{
	t_list	*node;
	int		max_value;
	int		max_pos;
	int		pos;

	node = b;
	max_value = b->data;
	max_pos = 0;
	pos = 0;
	while (node)
	{
		if (node->data > max_value)
		{
			max_value = node->data;
			max_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (max_pos);
}
void	push_b_to_a(t_list **a, t_list **b)
{
	int	pos;
	int	size_b;
	int	steps;

	pos = find_b_max(*b);
	size_b = list_size(*b);
	steps = size_b - pos;
	if (pos <= size_b / 2)
	{
		while (pos > 0)
		{
			rb(b);
			pos--;
		}
	}
	else
	{
		while (steps > 0)
		{
			rrb(b);
			steps--;
		}
	}
	pa(a, b);
}
