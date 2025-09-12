/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:07:28 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/12 10:57:30 by esakgul          ###   ########.fr       */
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

/* stack utils */
t_list	*add_node(int data);
void	add_front(t_list **head, t_list *new_node);
void	add_back(t_list **head, t_list *new_node);
int		list_size(t_list *node);
void	free_stack(t_list **head);

/* parsing */
t_list	*parse(char *av[]);
int		ft_isnumber(char *str);
int		has_duplicate(t_list **a);
int		ft_safe_atoi(const char *s);
void	ft_free_split(char **arr);
void	ft_freesel(char **split, t_list **a);
int	parse_split(char *arg, t_list **a);


/* error / index helpers */
void	error_exit(void);
void	set_ranks(t_list *a);
void	index_node(t_list *a, int size);
int		pos_to_index(int pos, int size);

/* swap */
void	sb(t_list **b);
void	sa(t_list **a);
void	ss(t_list **a, t_list **b);

/* push */
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);

/* reverse rotate */
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

/* rotate */
void	rb(t_list **b);
void	ra(t_list **a);
void	rr(t_list **a, t_list **b);

/* push back from b to a */
int		find_b_max(t_list *b);
void	push_b_to_a(t_list **a, t_list **b);

/* sorting helpers */
void	number_up(t_list **a, t_list **b, int index_a, int index_b);
void	ft_sort_3(t_list **a);
int		index_find_b(t_list *b, int a_index);
int		step_count(int index_a, int index_b);
int		find_min_index(t_list *a, t_list *b);
void	sort_a_to_b(t_list **a, t_list **b);

#endif
