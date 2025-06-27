#include "../../inc/push_swap.h"

bool    sorted(t_node *stack)
{
    while (stack && stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}
