/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:00:22 by scheragh          #+#    #+#             */
/*   Updated: 2025/07/21 14:00:09 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"
#include <stdio.h>

static void	push(t_node **dest, t_node **src)
{
	t_node	*push;

	if (!*src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dest)
	{
		*dest = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dest;
		(*dest)->prev = push;
		*dest = push;
	}
}

void	pa(t_node **a, t_node **b, bool printed)
{
	push(a, b);
	printf("Here inside pa its done!");
	if (!printed)
		ft_printf("pa\n");
}

void	pb(t_node **b, t_node **a, bool printed)
{
	push(b, a);
	printf("Here inside pb its done!");
	if (!printed)
		ft_printf("pb\n");
}
