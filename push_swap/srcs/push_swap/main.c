#include "../../inc/push_swap.h"

int main(int argc, char **argv)
{
    t_node  *a;
    t_node  *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    init_stack(&a, argv + 1);
    if (!sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else if (stack_len(a) == 5)
            ft_printf("Sort five");
            //sort_five(&a);
        else
            ft_printf("Sort normal");
            //sort_stacks(&a, &b);
    }
    (void)b;
    free_stack(&a);
    return (0);
}
