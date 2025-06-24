#include "../../inc/push_swap.h"
#include <stdlib.h>

t_node  *ps_lstnew(int value)
{
    t_node  *node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->nbr = value;
    node->index = -1;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

void    ps_lstadd_back(t_node **stack, t_node *new)
{
    t_node  *last;

    if (!stack || !new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
    new->prev = last;
}
