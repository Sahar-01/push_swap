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
#include <limits.h>

t_node *get_min(t_node *stack)
{
	t_node *min_node;
	long min_val;

	if (!stack)
		return (NULL);
	min_val = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->nbr < min_val)
		{
			min_val = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node *get_max(t_node *stack)
{
	t_node *max_node;
	long max_val;

	if (!stack)
		return (NULL);
	max_val = LONG_MIN;
	max_node = NULL;
	while (stack)
	{
		if (stack->nbr > max_val)
		{
			max_val = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
