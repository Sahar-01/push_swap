/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:02:21 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 15:50:57 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

bool	sorted(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	reverse_sorted(t_node *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
