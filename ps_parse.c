/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:39:07 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/12 10:56:29 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_list **a)
{
	t_list	*p;
	t_list	*q;

	p = *a;
	while (p && p->next)
	{
		q = p->next;
		while (q)
		{
			if (p->data == q->data)
				return (1);
			q = q->next;
		}
		p = p->next;
	}
	return (0);
}
int	parse_split(char *arg, t_list **a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!ft_isnumber(split[j]))
			ft_freesel(split, a);
		add_back(a, add_node(ft_safe_atoi(split[j])));
		j++;
	}
	ft_free_split(split);
	return (1);
}
t_list	*parse(char *av[])
{
	int		i;
	t_list	*a;

	a = NULL;
	i = -1;
	while (av[++i])
	{
		if (!ft_isnumber(av[i]))
		{
			free_stack(&a);
			error_exit();
		}
		add_back(&a, add_node(ft_safe_atoi(av[i])));
	}
	if (has_duplicate(&a))
	{
		free_stack(&a);
		error_exit();
	}
	set_ranks(a);
	return (a);
}
