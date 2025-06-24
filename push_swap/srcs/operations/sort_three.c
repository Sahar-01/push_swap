#include "../../inc/push_swap.h"

void sort_three(t_node **a)
{
    t_node      *MAX_NODE;

    MAX_NODE = get_max(*a);
    if (MAX_NODE == *a)
        ra(a, false);
    else if ((*a)->next == MAX_NODE)
        rra(a, false);
     if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);      
}
