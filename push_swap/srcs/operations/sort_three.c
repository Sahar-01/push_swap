/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:02:55 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 15:50:28 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

bool	is_case_low_high_mid(t_node *a)
{
	if (!a || !a->next || !a->next->next)
		return (false);
	return (
		a->nbr < a->next->nbr
		&& a->nbr < a->next->next->nbr
		&& a->next->nbr > a->next->next->nbr
	);
}

void	sort_three(t_node **a)
{
	t_node	*max_node;

	max_node = get_max(*a);
	if (is_case_low_high_mid(*a))
	{
		sa(a, false);
		ra(a, false);
		return ;
	}
	if (max_node == *a)
		ra(a, false);
	else if ((*a)->next == max_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
