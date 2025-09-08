/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:07:28 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/05 14:58:13 by esakgul          ###   ########.fr       */
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

#endif
