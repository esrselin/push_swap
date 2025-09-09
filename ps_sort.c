/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:59:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/09 18:20:31 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_3(t_list **a)
{
    if((*a)->index == 0 && (*a)->next->index == 2)
    {
        rra(a);
        sa(a);
    }
    else if((*a)->index == 1)
    {
        if((*a)->next->index == 0)
            sa(a);
        else
            rra(a);
    }
    else if((*a)->index == 2)
    {
        if((*a)->next->index == 0)
            rra(a);
        else
        {
            sa(a);    
            rra(a);
        }
    }
}
int	index_find_b(t_list *b, int a_index)
{
	t_list	*node;
	int		pos;
	int		best_pos;
    int     best_index;

	if (!b)
		return (0);
	node = b;
	pos = 0;
	best_pos = 0;
	best_index = 0;
	while (node)
	{
		if (node->index > a_index)
		{
			best_index = node->index - a_index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	return (best_pos);
}
int	step_count(int index_a, int index_b)
{
	int	step;

	step = 0;
	if (index_a < 0 && index_b < 0)
	{
		if (index_a < index_b)
			step = index_a * -1;
		else
			step = index_b * -1;
	}
	else if (index_a > 0 && index_b > 0)
	{
		if (index_a > index_b)
			step = index_a;
		else
			step = index_b;
	}
	else if (index_a > 0 && index_b < 0)
		step = index_a + (index_b * -1);
	else if (index_a < 0 && index_b > 0)
		step = (index_a * -1) + index_b;

	return (step);
}

int	min_step(t_list *a, t_list *b)
{
	t_list	*node;
	int		i;
	int		min_index;
	int		min_step;
	int		step;
	int		pos_b;

	node = a;
	i = 0;
	min_index = a->index;
	min_step = -1;
	while (node)
	{
		pos_b = index_find_b(b, node->index);
		step = step_count(min_index, pos_b);
		if (min_step == -1 || step < min_step)
		{
			min_step = step;
			min_index = node->index;
		}
		node = node->next;
		i++;
	}
	return (min_index);
}
void	number_up(t_list **a, t_list **b, int index_a, int index_b)
{
	// ikisi de negatif
	if (index_a < 0 && index_b < 0)
	{
		while (index_a < 0 && index_b < 0)
		{
			rrr(a, b);
			index_a++;
			index_b++;
		}
		while (index_a < 0)
		{
			rra(a);
			index_a++;
		}
		while (index_b < 0)
		{
			rrb(b);
			index_b++;
		}
	}
	// ikisi de pozitif
	else if (index_a > 0 && index_b > 0)
	{
		while (index_a > 0 && index_b > 0)
		{
			rr(a, b);
			index_a--;
			index_b--;
		}
		while (index_a > 0)
		{
			ra(a);
			index_a--;
		}
		while (index_b > 0)
		{
			rb(b);
			index_b--;
		}
	}
	// a pozitif, b negatif
	else if (index_a > 0 && index_b < 0)
	{
		while (index_a > 0)
		{
			ra(a);
			index_a--;
		}
		while (index_b < 0)
		{
			rrb(b);
			index_b++;
		}
	}
	// a negatif, b pozitif
	else if (index_a < 0 && index_b > 0)
	{
		while (index_a < 0)
		{
			rra(a);
			index_a++;
		}
		while (index_b > 0)
		{
			rb(b);
			index_b--;
		}
	}
}


void	sort_a_to_b(t_list **a, t_list **b)
{
    int	a_size;
    int	target_index;
    int	pos_a;
    int	pos_b;

    a_size = list_size(*a);
    while (a_size > 3)
    {
        target_index = min_step(*a, *b);
        pos_a = position_in_stack(*a, target_index);
        pos_b = index_find_b(*b, target_index);
        //number_up(a, b, pos_a, pos_b);
        a_size--;
    }
    ft_sort_3(a);
    // sonra B’den A’ya geri al
}