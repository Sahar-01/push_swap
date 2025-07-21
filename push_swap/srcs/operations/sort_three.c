/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:02:55 by scheragh          #+#    #+#             */
/*   Updated: 2025/07/21 11:16:10 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

void	sort_three(t_node **a)
{
	t_node	*max_node;

	max_node = get_max(*a);
	if ((*a)->nbr < (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
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
