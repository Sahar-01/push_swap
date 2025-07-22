#include "../../inc/push_swap.h"
#include <stdio.h>

void sort_five(t_node **a, t_node **b)
{
    pb(b, a, false);
    pb(b, a, false);
    // Step 2: Sort remaining 3 in A (stub call)
    sort_three(a);
}
