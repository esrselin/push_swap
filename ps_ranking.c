/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ranking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:55:58 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/11 17:10:40 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_ranks(t_list *a)
{
	t_list	*i;
	t_list	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->data < i->data)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

int	pos_to_index(int pos, int size)
{
	int	half;

	half = size / 2;
	if (pos <= half)
		return (pos);
	else
		return (pos - size);
}