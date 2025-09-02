/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:07:28 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/01 18:13:39 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_list {
    int             data;
    struct s_list  *next;
} t_list;

t_list *add_node(int data);
void    add_front(t_list **head, t_list *new_node);
void    add_back(t_list **head, t_list *new_node);
int     list_size(t_list *node);

#endif
