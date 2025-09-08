/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:07:33 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/04 17:32:30 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int arr[], int n)
{
	int i;
	int key;
	int j;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

void	index_node(t_list *a, int arr[], int size)
{
	t_list *node;
	int     j;

	node = a;
	while (node)
	{
		j = 0;
		while (j < size)
		{
			if (node->data == arr[j])
			{
				node->index = j;
				break ;
			}
			j++;
		}
		node = node->next;
	}
}

void	partition(t_list **a)
{
	t_list	*node;
	int		*arr;
	int		i;
	int		size;

	size = list_size(*a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	node = *a;
	while (node)
	{
		arr[i++] = node->data;
		node = node->next;
	}
	sort_array(arr, size);
	index_node(*a, arr, size);
	free(arr);
}

