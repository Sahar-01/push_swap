#include "../../inc/push_swap.h"

static void rrotate(t_node **stack)
{
    t_node  *first_node;

    if (!*stack || !(*stack)->prev)
        return;
    first_node = find_first(*stack);
    first_node->prev = *stack;
    *stack = (*stack)->prev;
    (*stack)->prev = NULL;
    first_node->prev->next = first_node;
    first_node->prev->prev = NULL;
}

void    rra(t_node **a, bool printed)
{
    rrotate(a);
    if (!printed)
        ft_printf("rra\n");
}

void    rrb(t_node **b, bool printed)
{
    rrotate(b);
    if (!printed)
        ft_printf("rrb\n");
}

void    rrr(t_node **a, t_node **b, bool printed)
{
    rrotate(a);
    rrotate(b);
    if (!printed)
        ft_printf("rr\n");
}
