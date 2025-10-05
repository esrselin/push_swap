/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:15:35 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/03 17:15:36 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_list **stack)
{
	t_list	*node;
	t_list	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	while (node->next)
	{
		before_last = node;
		node = node->next;
	}
	before_last->next = NULL;
	add_front(stack, node);
}

void	rra(t_list **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
