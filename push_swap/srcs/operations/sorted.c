#include "../../inc/push_swap.h"

bool    sorted(t_node *stack)
{
    if (!stack)
        return (1);
    while(stack->next)
    {
        if (stack->nbr < stack->next->nbr)
            return (true);
        stack = stack->next;
    }
    return (false);
}
