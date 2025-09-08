/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:14:12 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/03 17:14:13 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*node;

	if (!b || !*b)
		return ;
	node = *b;
	*b = (*b)->next;
	node->next = *a;
	*a = node;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*node;

	if (!a || !*a)
		return ;
	node = *a;
	*a = (*a)->next;
	node->next = *b;
	*b = node;
	write(1, "pb\n", 3);
}
