/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:34:14 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/13 15:41:18 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_window(int *low, int *high, int n, int chunk_sz)
{
	*low += chunk_sz;
	*high = *low + chunk_sz - 1;
	if (*high >= n)
		*high = n - 1;
}

static void	process_chunk_element(t_list **a, t_list **b,
	int low, int high)
{
	int	pos;
	int	mid_of_window;

	pos = pos_in_range(*a, low, high);
	if (pos == -1)
		return ;
	rotate_to_top_a(a, pos);
	pb(a, b);
	mid_of_window = low + (high - low) / 2;
	if (*b && (*b)->next && (*b)->index <= mid_of_window)
		rb(b);
}

static void	prepare_chunks(int n, int *chunk_cnt, int *chunk_sz)
{
	*chunk_cnt = get_chunk_count(n);
	if (*chunk_cnt < 1)
		*chunk_cnt = 1;
	*chunk_sz = (n + *chunk_cnt - 1) / *chunk_cnt;
}

void	chunk_sort(t_list **a, t_list **b)
{
	int	n;
	int	chunk_cnt;
	int	chunk_sz;
	int	low;
	int	high;

	n = list_size(*a);
	prepare_chunks(n, &chunk_cnt, &chunk_sz);
	low = 0;
	high = low + chunk_sz - 1;
	if (high >= n)
		high = n - 1;
	while (*a)
	{
		if (pos_in_range(*a, low, high) == -1)
			update_window(&low, &high, n, chunk_sz);
		else
			process_chunk_element(a, b, low, high);
	}
	push_back_max(b, a);
}
