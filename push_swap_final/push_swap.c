/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 15:55:53 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/15 15:55:54 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0);
	a = parse(argv + 1);
	b = NULL;
	if (list_size(a) <= 1)
	{
		free_stack(&a);
		return (0);
	}
	sort_stacks(&a, &b);
	free_stack(&a);
	return (0);
}
