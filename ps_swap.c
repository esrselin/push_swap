/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:21:15 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/03 18:30:26 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s_stack(t_list **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
}

void	sa(t_list **a)
{
	s_stack(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	s_stack(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	s_stack(a);
	s_stack(b);
	write(1, "ss\n", 3);
}
