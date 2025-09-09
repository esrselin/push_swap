/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:07:33 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/09 18:01:20 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_node(t_list *a, int size)
{
	t_list	*node;
	int		pos;
	int		half;

	node = a;
	pos = 0;
	half = size / 2;
	while (node)
	{
		if (pos < half)
			node->index = half - 1 - pos;
		else
			node->index = -(pos - half + 1);
		pos++;
		node = node->next;
	}
}

