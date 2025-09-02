#include "push_swap.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
static void	ft_free_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}


int	ft_isnumber(char *str)
{
	int i = 0;
	int digits = 0;

	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		digits++;
		i++;
	}
	return (digits > 0);
}

static int	safe_atoi(const char *s)
{
	long	sign = 1;
	long	res = 0;
	int		i = 0;

	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
            error_exit();
		i++;
	}
	return ((int)(res * sign));
}

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

void freesel(char **split, t_list **a)
{
    write(2, "Error\n", 6);
	ft_free_split(split);
	free_stack(a);
	exit(1);
}

t_list	*parse(char *av[])
{
	int		i;
	int		j;
	t_list	*a;
	char	**split;

	i = -1;
	a = NULL;
	while (av[++i])
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!ft_isnumber(split[j]))
                freesel(split,&a);
			add_back(&a, add_node(safe_atoi(split[j])));
			j++;
		}
		ft_free_split(split);
	}
	if (has_duplicate(&a))
        free_stack(&a), error_exit();
	return (a);
}
