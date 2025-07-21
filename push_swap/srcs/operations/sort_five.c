#include "../../inc/push_swap.h"
#include <stdio.h>

void	sort_five(t_node **a, t_node **b)
{

	printf("%d", (*a));
	//Push the first two off
	pa(a, b, false);
	pa(a, b, false);
	while((*b))
	{
		printf("%d", (*b)->nbr)
		(*b) = (*b)->next;
	}
	//Sort the remaining 3 in stack as
	sort_three((a));
	if ((*b)->nbr > (*a)->next->next->nbr)
	{
		if ((*b)->nbr < ((*a)->next->nbr))
		{
			pa(b, a, false);
			ra(a, false);
		}
	}
}
