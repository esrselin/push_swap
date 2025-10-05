/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:30:33 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/02 18:17:51 by esakgul          ###   ########.fr       */
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
//DÜZELT
void	chunk_sort(t_list **a, t_list **b)
{
	int		n;
	int		chunk_cnt;
	int		chunk_sz;
	int		low;
	int		high;
	int		pos;
	int		mid_of_window;

	n = list_size(*a);
	chunk_cnt = get_chunk_count(n);
	if (chunk_cnt < 1)
		chunk_cnt = 1;
	chunk_sz = (n + chunk_cnt - 1) / chunk_cnt;
	low = 0;
	high = low + chunk_sz - 1;
	if (high >= n)
		high = n - 1;
	while (*a)
	{
		pos = pos_in_range(*a, low, high);
		if (pos == -1)
		{
			low += chunk_sz;
			high = low + chunk_sz - 1;
			if (high >= n)
				high = n - 1;
			continue ;
		}
		rotate_to_top_a(a, pos);
		pb(a, b);
		mid_of_window = low + (high - low) / 2;
		if (*b && (*b)->next && (*b)->index <= mid_of_window)
			rb(b);
	}
	push_back_max(b, a);
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
