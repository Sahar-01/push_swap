#include "../../inc/push_swap.h"

int stack_len(t_node *stack)
{
    int     count;

    count = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}

t_node  *get_max(t_node *stack)
{
    long    MAX;
    t_node  *max_node;

    MAX = LONG_MIN;
    if (!stack)
        return (0);
    while (stack)
    {
        if (stack->nbr > MAX)
        {
            MAX = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}

void    free_stack(t_node **stack) //Define a function to free a stack if there are errors
{
    t_node    *tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
    t_node    *current;

    if (!stack) //Check for an empty stack
        return ;
    current = *stack;
    while (current) //As long as a node exist in the stack
    {
        tmp = current->next; //Assign to `tmp` the pointer to the next node
        current->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
        free(current); //Free the current node, deallocating the memory occupied by that node
        current = tmp; //Assign `tmp` as the current first node
    }
    *stack = NULL;
}

t_node    *find_last(t_node *stack) //Define a function that returns the pointer to the last node
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

t_node  *find_first(t_node *stack)
{
    if(!stack)
        return (NULL);
    while (stack->prev)
        stack = stack->prev;
    return (stack);
}
