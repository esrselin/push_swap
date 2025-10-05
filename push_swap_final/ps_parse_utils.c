/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esakgul <esakgul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:31:16 by esakgul           #+#    #+#             */
/*   Updated: 2025/10/02 17:27:36 by esakgul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
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
	int	i;
	int	digits;

	i = 0;
	digits = 0;
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

int	ft_safe_atoi(const char *s)
{
	long	sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		res = res * 10 + (s[i] - '0');
		if ((sign == 1 && res > 2147483647)
			|| (sign == -1 && res > 2147483648))
			error_exit();
		i++;
	}
	return ((int)(res * sign));
}

void	ft_freesel(char **split, t_list **a)
{
	write(2, "Error\n", 6);
	ft_free_split(split);
	free_stack(a);
	exit(1);
}
