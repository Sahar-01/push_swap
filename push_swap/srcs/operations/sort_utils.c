/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 08:12:47 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 15:46:17 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

t_node	*get_min(t_node *stack)
{
	t_node	*min_node;
	long	min_val;

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

t_node	*get_max(t_node *stack)
{
	t_node	*max_node;
	long	max_val;

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

bool	is_hardcode_five_case(t_node *a)
{
	return (a
		&& a->index == 2
		&& a->next && a->next->index == 4
		&& a->next->next && a->next->next->index == 3
		&& a->next->next->next && a->next->next->next->index == 1
		&& a->next->next->next->next && a->next->next->next->next->index == 0);
}
