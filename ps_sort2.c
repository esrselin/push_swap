#include "push_swap.h"

// A’da seçilen elemanın B’de hangi pozisyona gitmesi gerektiğini bul
int	index_find_b(t_list *b, int a_index)
{
	t_list	*node;
	int		pos;
	int		best_pos;
	int		best_diff;

	if (!b)
		return (0);
	node = b;
	pos = 0;
	best_pos = 0;
	best_diff = 2147483647;
	while (node)
	{
		if (node->index > a_index && node->index - a_index < best_diff)
		{
			best_diff = node->index - a_index;
			best_pos = pos;
		}
		node = node->next;
		pos++;
	}
	if (best_diff == 2147483647)
		best_pos = 0;
	return (best_pos);
}

// adım maliyeti
int	step_count(int pos_a, int pos_b, int size_a, int size_b)
{
	if (pos_a > size_a / 2)
		pos_a = pos_a - size_a;
	if (pos_b > size_b / 2)
		pos_b = pos_b - size_b;

	// abs yerine if/else ile pozitif yap
	if (pos_a < 0)
		pos_a = pos_a * -1;
	if (pos_b < 0)
		pos_b = pos_b * -1;

	if ((pos_a >= 0 && pos_b >= 0) || (pos_a <= 0 && pos_b <= 0))
	{
		if (pos_a > pos_b)
			return (pos_a);
		return (pos_b);
	}
	return (pos_a + pos_b);
}


// A’daki en uygun elemanı bul
int	min_step(t_list *a, t_list *b)
{
	t_list	*node;
	int		i;
	int		best_index;
	int		best_step;
	int		step;
	int		pos_b;

	node = a;
	i = 0;
	best_index = a->index;
	best_step = -1;
	while (node)
	{
		pos_b = index_find_b(b, node->index);
		step = step_count(i, pos_b, list_size(a), list_size(b));
		if (best_step == -1 || step < best_step)
		{
			best_step = step;
			best_index = node->index;
		}
		node = node->next;
		i++;
	}
	return (best_index);
}

// A ve B’yi uygun yere döndür
void	number_up(t_list **a, t_list **b, int pos_a, int pos_b)
{
	int	size_a = list_size(*a);
	int	size_b = list_size(*b);

	if (pos_a > size_a / 2)
		pos_a = pos_a - size_a;
	if (pos_b > size_b / 2)
		pos_b = pos_b - size_b;
	while (pos_a > 0 && pos_b > 0)
	{
		rr(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a < 0 && pos_b < 0)
	{
		rrr(a, b);
		pos_a++;
		pos_b++;
	}
	while (pos_a > 0)
	{
		ra(a);
		pos_a--;
	}
	while (pos_a < 0)
	{
		rra(a);
		pos_a++;
	}
	while (pos_b > 0)
	{
		rb(b);
		pos_b--;
	}
	while (pos_b < 0)
	{
		rrb(b);
		pos_b++;
	}
	pb(a, b);
}

// A’dan B’ye taşı
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
		number_up(a, b, pos_a, pos_b);
		a_size--;
	}
	ft_sort_3(a);
	// sonra B’den A’ya geri al
}
