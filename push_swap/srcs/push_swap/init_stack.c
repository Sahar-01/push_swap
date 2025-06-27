#include "../../inc/push_swap.h"
#include <limits.h>

static long	ps_atol(const char *s)
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
	while (*s && ft_isdigit(*s))
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

static void	ps_error(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	validate_and_push(t_node **a, long v)
{
	t_node	*tmp;

	if (v < INT_MIN || v > INT_MAX)
		ps_error(NULL);
	tmp = *a;
	while (tmp)
	{
		if (tmp->nbr == (int)v)
			ps_error(NULL);
		tmp = tmp->next;
	}
	ps_lstadd_back(a, ps_lstnew((int)v));
}

void	index_stack(t_node **stack)
{
	t_node	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
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
			ps_error(split);
		j = 0;
		while (split[j])
		{
			val = ps_atol(split[j]);
			validate_and_push(a, val);
			free(split[j++]);
		}
		free(split);
		i++;
	}
	index_stack(a);
}
