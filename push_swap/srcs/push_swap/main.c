/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:39 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 16:07:43 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

static void	run_push_swap(char **args, t_node **a, t_node **b)
{
	int		size;

	init_stack(a, args);
	if (sorted(*a))
	{
		free_stack(a);
		return ;
	}
	size = stack_len(*a);
	if (size == 2)
		sa(a, false);
	else if (size == 3)
		sort_three(a);
	else if (size == 5)
		sort_five(a, b);
	else
		sort_main(a, b);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	run_push_swap(argv + 1, &a, &b);
	return (0);
}
