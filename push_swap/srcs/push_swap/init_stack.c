#include "../../inc/push_swap.h"
#include <limits.h>

/* convert ascii to long (no overflow check here; we check later) */
static long ft_atol(const char *s)
{
    long    res;
    int     sign;

    res = 0;
    sign = 1;
    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
        if (*s++ == '-')
            sign = -1;
    while (*s && ft_isdigit(*s))
        res = res * 10 + (*s++ - '0');
    return (res * sign);
}

/* raise an error, free args if needed, and exit */
static void ps_error(char **args)
{
    if (args)
        free(args);
    ft_putstr_fd("Error\n", 2);
    exit(EXIT_FAILURE);
}

/* ensure value fits in 32-bit signed int and is not duplicated */
static void validate_and_push(t_node **a, long v)
{
    t_node  *new;
    t_node  *tmp;

    if (v < INT_MIN || v > INT_MAX)
        ps_error(NULL);
    tmp = *a;
    while (tmp)
    {
        if (tmp->nbr == (int)v)
            ps_error(NULL);
        tmp = tmp->next;
    }
    new = ps_lstnew((int)v);
    if (!new)
        ps_error(NULL);
    ps_lstadd_back(a, new);
}
void index_stack(t_node **stack)
{
    // Example placeholder: assign increasing indexes
    t_node *tmp = *stack;
    int i = 0;

    while (tmp)
    {
        tmp->index = i++;  // Make sure you have an `index` field!
        tmp = tmp->next;
    }
}
void    init_stack(t_node **a, char **argv)
{
    int     i;
    long    val;

    i = 0;
    while (argv[i])
    {
        val = ft_atol(argv[i]);
        validate_and_push(a, val);
        i++;
    }
    index_stack(a);
}
