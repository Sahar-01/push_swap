/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:47:07 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 20:04:32 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

static int	get_max_bit_count(t_node *stack)
{
	int		max_index;
	int		bit_count;

	max_index = 0;
	bit_count = 0;
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	while ((max_index >> bit_count) != 0)
		bit_count++;
	return (bit_count);
}

static void	push_by_bit(t_node **a, t_node **b, int bit_pos, int total_elements)
{
	int		count;

	count = 0;
	while (count < total_elements)
	{
		if ((((*a)->index >> bit_pos) & 1) == 1)
			ra(a, false);
		else
			pb(b, a, false);
		count++;
	}
}

static void	move_back_to_a(t_node **a, t_node **b)
{
	while (*b)
		pa(a, b, false);
}

void	sort_main(t_node **a, t_node **b)
{
	int		bit_pos;
	int		total_elements;
	int		max_bits;

	bit_pos = 0;
	total_elements = stack_len(*a);
	max_bits = get_max_bit_count(*a);
	while (bit_pos < max_bits)
	{
		push_by_bit(a, b, bit_pos, total_elements);
		move_back_to_a(a, b);
		bit_pos++;
	}
}
