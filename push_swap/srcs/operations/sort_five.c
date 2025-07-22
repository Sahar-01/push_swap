#include "../../inc/push_swap.h"
#include <stdio.h>

void	swap_stack_b(t_node *node1, t_node *node2)
{
	t_node	*tmp;
	if(node1->nbr > node2->nbr)
	{
		node1 = tmp;
		node2 = node1;
		tmp = node2;
	}
}

void	insert_first(t_node **a, t_node **b, t_node *node1, int min, int max)
{
	if (node1->nbr == max)
	{
		pa(a, b, false);
		ra(a, false);
	}
	else if(node1->nbr == min)
		pa(a, b, false);
	else
	{
		if ((node1->nbr > (*a)->nbr) && (node1->nbr < (*a)->next->nbr))
		{
			pa(a, b, false);
			sa(a, false);
		}
		if((node1->nbr < max) && (node1->nbr > (*a)->next->nbr))
		{
			pa(a, b, false);
			rra(a, false);
			rra(a, false);
			rra(a, false);
			rra(a, false);
		}
	}
}

void	insert_second(t_node **a, t_node **b, t_node *node2, int min, int max)
{
	if (node2->nbr == max)
	{
		pa(a, b, false);
		ra(a, false);
	}
	else if(node2->nbr == min)
		pa(a, b, false);
	else
	{
		pa(a, b, false);
	}
}

void	sort_five(t_node **a, t_node **b)
{
	int		val;
	t_node	*insert1;
	t_node	*insert2;
	int		max;
	int		min;

	min = get_min(a);
	max = get_max(a);
	val = -8743974;
    pb(b, a, false);
    pb(b, a, false);
	insert1 = (*b);
	insert2 = insert1->next;
	sort_three(a);
	swap_stack_b(insert1, insert2);
    insert_first(a, b, insert1, min, max);
	insert_second(a, b, insert2, min, max);
}
