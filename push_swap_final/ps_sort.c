/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:30:33 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/13 15:41:07 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

static void	sort_three(t_list **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->data;
	y = (*a)->next->data;
	z = (*a)->next->next->data;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static void	sort_upto_five(t_list **a, t_list **b)
{
	int	size;
	int	pos;

	size = list_size(*a);
	while (size > 3)
	{
		pos = min_index_pos(*a);
		rotate_to_top_a(a, pos);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_stacks(t_list **a, t_list **b)
{
	int	n;

	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	partition(a);
	n = list_size(*a);
	if (n <= 3)
		sort_three(a);
	else if (n <= 5)
		sort_upto_five(a, b);
	else
		chunk_sort(a, b);
}
