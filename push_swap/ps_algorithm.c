/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:59:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/09/08 14:37:17 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_count(int size)
{
	if (size <= 10)
		return (1);
	if (size <= 100)
		return (5);
	return (11);
}
void chunk(t_list **a, t_list **b)
{
    int chunk_size;
    
    int	low = 0;
	int	high = chunk_size - 1;
    
    chunk_size = (list_size(a) / get_chunk_count(a));
	while (*a)
	{
		if ((*a)->index >= low && (*a)->index <= high)
		{
			pb(a, b);
			// küçük yarıdaysa rb(b);
		}
		else
		{
			int pos = position_in_a(*a, low, high);
			if (pos <= list_size(*a) / 2)
				ra(a);
			else
				rra(a);
		}
		if (chunk finished)
		{
			low += chunk_size;
			high += chunk_size;
		}
	}
}
// void chunk(t_list **a, t_list** b)
// {
//     int i;
//     int pivot;
//     int j;
//     t_list *node;

//     node = a;
//     pivot = chunk_size(a) - 1;
//     j = 0;
//     i = 0;
//     while(chunk_size(a) >= j)
//     {
//         while(node != NULL)
//         {
//             if(node->index >= i && node->index <= pivot)
//                 pb(node,b);
//             else
//             {
//                 if(list_size(a) / 2 <= )
//                     ra(node);
//                 else
//                     rra(node);
//             }
//             node = node->next;
//             i++;
//         }
//         i += 1;
//         pivot += chunk_size(a);
//         j++; 
//     }
// }
/*

    10 < n <= 100 -> 5 chunk
    100 < n <= 500 -> 11 chunk
    
    n<=10 için ayrı algoritma yaz
    n > 11 için,
    chunklara böl 
    o indextekileri b stackine at
    b stackinde index sırası büyükten küçüğe rb/rrb/sb yap
    rb/rrb/sb maliyet hesabında hangisi azsa onu yap
    a'ya at
*/

/*
    0-200
    chunk 5
    0-4
    5-9

*/

/*

    while bütün
        while chunk aralığını kontrol 0-4 5-9 10-14
            indextekileri pb
            yoksa ra
            
    pivot = chunksize-1
    i 0
    pivot schunk kadr artcak
    i = i + 1;
    pivot = pivot + s_chunk;
    ----------------------

    list size / 2: küçükse ra büyükse rra
*/

/*

    list 100
    chunk size = 20
    
    while(20 >= 0)
    {
        while(19 >= 0)
        {
            
        }
    }

bütün stacki tara
uygunları pbye at
kalan list size/ < ra yap
> rra yap



*/