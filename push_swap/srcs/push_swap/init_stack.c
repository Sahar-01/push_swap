/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:17:54 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 16:19:15 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

static void	ps_error(char **arr, t_node **a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	if (a)
	{
		while (*a)
		{
			tmp = (*a)->next;
			free(*a);
			*a = tmp;
		}
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static long	ps_atol(const char *s, t_node **a)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s)
		ps_error(NULL, a);
	while (*s && ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && (-res) < INT_MIN))
			ps_error(NULL, a);
		s++;
	}
	if (*s != '\0')
		ps_error(NULL, a);
	return (res * sign);
}

static void	validate_and_push(t_node **a, long val)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->nbr == (int)val)
			ps_error(NULL, a);
		tmp = tmp->next;
	}
	ps_lstadd_back(a, ps_lstnew((int)val));
}

void	index_stack(t_node **stack)
{
	int		index;
	t_node	*curr;
	t_node	*cmp;

	curr = *stack;
	while (curr)
	{
		index = 0;
		cmp = *stack;
		while (cmp)
		{
			if (cmp->nbr < curr->nbr)
				index++;
			cmp = cmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

void	init_stack(t_node **a, char **argv)
{
	int		i;
	int		j;
	long	val;
	char	**split;

	i = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split || !*split)
			ps_error(split, a);
		j = 0;
		while (split[j])
		{
			val = ps_atol(split[j], a);
			validate_and_push(a, val);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	index_stack(a);
}
