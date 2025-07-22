/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:39 by scheragh          #+#    #+#             */
/*   Updated: 2025/06/27 10:15:41 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	a = NULL;
	if (argc == 1)
		return (0);
	init_stack(&a, argv + 1);
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) == 5)
			sort_five(&a, &b);
		else
			printf("very cool");
	}
	free_stack(&a);
	return (0);
}
