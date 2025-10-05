/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:07:28 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/02 17:40:19 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*add_node(int data);
void	add_front(t_list **head, t_list *new_node);
void	add_back(t_list **head, t_list *new_node);
int		list_size(t_list *node);
void	free_stack(t_list **head);

t_list	*parse(char *av[]);
int		ft_isnumber(char *str);
int		has_duplicate(t_list **a);
int		ft_safe_atoi(const char *s);
void	ft_free_split(char **arr);
void	ft_freesel(char **split, t_list **a);

void	sb(t_list **b);
void	sa(t_list **a);
void	ss(t_list **a, t_list **b);

void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	rb(t_list **b);
void	ra(t_list **a);
void	rr(t_list **a, t_list **b);

void	partition(t_list **a);

int		get_chunk_count(int size);
void	sort_stacks(t_list **a, t_list **b);
void	chunk_sort(t_list **a, t_list **b);
int		max_index_pos(t_list *s, int *out_max);
void	rotate_to_top_a(t_list **a, int pos);
void	push_back_max(t_list **b, t_list **a);

int		pos_in_range(t_list *a, int low, int high);
int		min_index_pos(t_list *s);
int		max_index_pos(t_list *s, int *out_max);

#endif
