/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:12:47 by scheragh          #+#    #+#             */
/*   Updated: 2025/07/21 08:24:19 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

t_node	*get_max(t_node *stack)
{
	long	max;
	t_node	*max_node;

	max = LONG_MIN;
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*get_min(t_node *stack)
{
	long	min;
	t_node	*min_node;

	min = LONG_MAX;
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
