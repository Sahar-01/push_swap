#include "../../inc/push_swap.h"
#include <stdio.h>

bool is_ok(t_node **a, int val)
{
    if (!a || !*a)
        return true;

    t_node *top = *a;
    t_node *next = top->next;
    if (val < top->nbr && (!next || val > next->nbr))
        return true;
    if (next && val > top->nbr && val < next->nbr)
        return true;
    if (next && top->nbr > next->nbr)
    {
        if (val > top->nbr || val < next->nbr)
            return true;
    }
    return false;
}

void sort_five(t_node **a, t_node **b)
{
	int		val;

	val = -8743974;
    pb(b, a, false);
    pb(b, a, false);
    // Step 2: Sort remaining 3 in A (stub call)
    sort_three(a);
	while(*b)
	{
		val = (*b)->nbr;
		while(!is_ok(a, val))
			ra(a, false);
		pa(a, b, false);
	}
}
