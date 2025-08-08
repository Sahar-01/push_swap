/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:36:46 by scheragh          #+#    #+#             */
/*   Updated: 2025/08/08 15:43:29 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

int	lstsize(t_node *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_node	*find_node_with_nbr(t_node *stack, int nbr)
{
	while (stack)
	{
		if (stack->nbr == nbr)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*get_tail(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	hard_coded_sort(t_node **a, t_node **b)
{
	if (reverse_sorted(*a))
	{
		pb(b, a, false);
		pb(b, a, false);
		ra(a, false);
		sa(a, false);
		pa(a, b, false);
		ra(a, false);
		pa(a, b, false);
		ra(a, false);
	}
	else if (is_hardcode_five_case(*a))
	{
		pb(b, a, false);
		pb(b, a, false);
		ra(a, false);
		sa(a, false);
		pa(a, b, false);
		ra(a, false);
		ra(a, false);
		ra(a, false);
		pa(a, b, false);
		rra(a, false);
		rra(a, false);
	}
}

void	sort_five(t_node **a, t_node **b)
{
	t_node	*min_node;

	if ((reverse_sorted(*a) && stack_len(*a) == 5) || is_hardcode_five_case(*a))
	{
		hard_coded_sort(a, b);
		return ;
	}
	while (lstsize(*a) > 3)
	{
		min_node = get_min(*a);
		if (*a == min_node)
			pb(b, a, false);
		else
			ra(a, false);
	}
	sort_three(a);
	pa(a, b, false);
	pa(a, b, false);
	while ((*a)->nbr != get_min(*a)->nbr)
		ra(a, false);
}
