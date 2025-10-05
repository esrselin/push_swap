/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:24:35 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/05 14:57:55 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_node(int data)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->data = data;
	tmp->index = -44;
	tmp->next = NULL;
	return (tmp);
}

void	add_front(t_list **head, t_list *new)
{
	if (!head || !new)
		return ;
	new->next = *head;
	*head = new;
}

void	add_back(t_list **head, t_list *new)
{
	t_list	*cur;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

int	list_size(t_list *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	free_stack(t_list **head)
{
	t_list	*cur;
	t_list	*tmp;

	if (!head)
		return ;
	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*head = NULL;
}
