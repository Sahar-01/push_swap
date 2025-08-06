#include "../../inc/push_swap.h"

static void insert_element(t_node **a, t_node **b, t_node *overall_min, t_node *overall_max)
{
    int count = 0;
    t_node *min = get_min(*a);
    t_node *max = get_max(*a);

    if ((*b)->nbr == overall_max->nbr || (*b)->nbr > max->nbr)
    {
        pa(a, b, false);
        ra(a, false);
    }
    else if ((*b)->nbr == overall_min->nbr || (*b)->nbr < min->nbr)
        pa(a, b, false);
    else
    {
        while ((*a)->index < (*b)->index && count < 3)
        {
            ra(a, false);
            count++;
        }
        pa(a, b, false);
        while (count > 0)
        {
            rra(a, false);
            count--;
        }
    }
}

void sort_five(t_node **a, t_node **b)
{
    t_node *overall_min;
    t_node *overall_max;

    overall_min = get_min(*a);
    overall_max = get_max(*a);
    pb(b, a, false);
    pb(b, a, false);
    sort_three(a);
    insert_element(a, b, overall_min, overall_max);
    insert_element(a, b, overall_min, overall_max);
}