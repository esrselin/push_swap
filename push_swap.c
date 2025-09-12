/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:44:00 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/12 10:53:09 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_list **a, t_list **b)
{
	int	size;

	size = list_size(*a);
	if (size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (size == 3)
		ft_sort_3(a);
	else
	{
		sort_a_to_b(a, b);
		while (*b)
			push_b_to_a(a, b);
	}
}
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = parse(argv + 1);
	b = NULL;
	if (list_size(a) == 1)
	{
		free_stack(&a);
		return (0);
	}
	sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}

