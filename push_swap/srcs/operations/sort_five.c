#include "../../inc/push_swap.h"
#include <stdio.h>

int lstsize(t_node *lst)
{
    int count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return count;
}

t_node *find_node_with_nbr(t_node *stack, int nbr)
{
    while (stack)
    {
        if (stack->nbr == nbr)
            return stack;
        stack = stack->next;
    }
    return NULL;
}

t_node *get_tail(t_node *stack)
{
    if (!stack)
        return NULL;
    while (stack->next)
        stack = stack->next;
    return stack;
}

// A simple, robust sort_five implementation
void sort_five(t_node **a, t_node **b)
{
    t_node *min_node;

    // Push the two smallest elements to b
    while (lstsize(*a) > 3)
    {
        min_node = get_min(*a);
        if (*a == min_node)
            pb(b, a, false);
        else
            ra(a, false);
    }

    // Sort the remaining three elements
    sort_three(a);

    // Push the two elements back from b to a
    pa(a, b, false);
    pa(a, b, false);

    // Final rotation to ensure the smallest element is at the top
    while ((*a)->nbr != get_min(*a)->nbr)
        ra(a, false);
}