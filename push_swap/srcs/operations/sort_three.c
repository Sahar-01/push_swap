#include "../../inc/push_swap.h"

void    sort_three(t_node **a)
{
    int first;
    int second;
    int third;

    first = (*a)->nbr;
    second = (*a)->next->nbr;
    third = (*a)->next->next->nbr;
    if (first > second && second < third && first < third)
        sa(a, false);
    else if (first > second && second > third)
    {
        sa(a, false);
        rra(a, false);
    }
    else if (first > second && second < third && first > third)
        ra(a, false);
    else if (first < second && second > third && first < third)
    {
        sa(a, false);
        ra(a, false);
    }
    else if (first < second && second > third && first > third)
        rra(a, false);
}
