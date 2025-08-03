#include "../../inc/push_swap.h"

int get_min_nbr(t_node *a)
{
    int min = a->nbr;
    while (a)
    {
        if (a->nbr < min)
            min = a->nbr;
        a = a->next;
    }
    return min;
}

int get_pos(t_node *a, int val)
{
    int i = 0;
    while (a)
    {
        if (a->nbr == val)
            return i;
        i++;
        a = a->next;
    }
    return -1; // Should not happen if val is in the stack
}

void sort_five(t_node **a, t_node **b)
{
    int min;

    while (stack_len(*a) > 3)
    {
        min = get_min_nbr(*a);
        while ((*a)->nbr != min)
        {
            if (get_pos(*a, min) <= stack_len(*a) / 2)
                ra(a, false);
            else
                rra(a, false);
        }
        pb(b, a, false); // push the smallest to B
    }

    sort_three(a); // sort remaining 3 in A

    while (*b)
        pa(a, b, false); // push back from B to A
}
