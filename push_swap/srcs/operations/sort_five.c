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

void sort_five(t_node **a, t_node **b)
{
    t_node *min_node;

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