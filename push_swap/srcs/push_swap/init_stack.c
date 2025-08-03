#include "../../inc/push_swap.h"

static void ps_error(char **arr)
{
    int i = 0;
    if (arr)
    {
        while (arr[i])
            free(arr[i++]);
        free(arr);
    }
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

static long ps_atol(const char *s)
{
    long res = 0;
    int sign = 1;

    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    if (!*s)
        ps_error(NULL);
    while (*s && ft_isdigit(*s))
    {
        res = res * 10 + (*s - '0');
        if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
            ps_error(NULL);
        s++;
    }
    if (*s != '\0')
        ps_error(NULL);
    return (res * sign);
}

static void validate_and_push(t_node **a, long val)
{
    t_node *tmp = *a;
    while (tmp)
    {
        if (tmp->nbr == (int)val)
            ps_error(NULL);
        tmp = tmp->next;
    }
    ps_lstadd_back(a, ps_lstnew((int)val));
}

void index_stack(t_node **stack)
{
    t_node *curr = *stack;
    while (curr)
    {
        int index = 0;
        t_node *cmp = *stack;
        while (cmp)
        {
            if (cmp->nbr < curr->nbr)
                index++;
            cmp = cmp->next;
        }
        curr->index = index;
        curr = curr->next;
    }
}

void init_stack(t_node **a, char **argv)
{
    int i = 0;
    while (argv[i])
    {
        char **split = ft_split(argv[i], ' ');
        if (!split || !*split)
            ps_error(split);
        int j = 0;
        while (split[j])
        {
            long val = ps_atol(split[j]);
            validate_and_push(a, val);
            free(split[j]);
            j++;
        }
        free(split);
        i++;
    }
    index_stack(a);
}
