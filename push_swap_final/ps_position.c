/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:29:46 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/02 17:40:57 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index_pos(t_list *s)
{
	int		pos;
	int		best_pos;
	int		best_idx;
	t_list	*cur;

	pos = 0;
	best_pos = 0;
	best_idx = 2147483647;
	cur = s;
	while (cur)
	{
		if (cur->index < best_idx)
		{
			best_idx = cur->index;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (best_pos);
}

int	max_index_pos(t_list *s, int *out_max)
{
	int		pos;
	int		best_pos;
	int		best_idx;
	t_list	*cur;

	pos = 0;
	best_pos = 0;
	best_idx = -2147483648;
	cur = s;
	while (cur)
	{
		if (cur->index > best_idx)
		{
			best_idx = cur->index;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	if (out_max)
		*out_max = best_idx;
	return (best_pos);
}

int	pos_in_range(t_list *a, int low, int high)
{
	int		pos;
	t_list	*cur;

	pos = 0;
	cur = a;
	while (cur)
	{
		if (cur->index >= low && cur->index <= high)
			return (pos);
		pos++;
		cur = cur->next;
	}
	return (-1);
}
