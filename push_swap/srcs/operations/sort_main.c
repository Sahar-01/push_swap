/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:47:07 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 15:53:00 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"
#include <stdio.h>

static int	get_max_bits(t_node *stack)
{
	int		max;
	int		bits;

	max = 0;
	bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_main(t_node **a, t_node **b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_node	*head;

	size = stack_len(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				ra(a, false);
			else
				pb(b, a, false);
			j++;
		}
		while (*b)
			pa(a, b, false);
		i++;
	}
}
