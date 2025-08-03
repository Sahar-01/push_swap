/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:14:39 by scheragh          #+#    #+#             */
/*   Updated: 2025/06/27 10:15:41 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/push_swap.h"

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *b = NULL;
    int size;

    if (argc < 2)
        return (0);

    init_stack(&a, argv + 1);

    if (sorted(a))
    {
        free_stack(&a);
        return (0);
    }

    size = stack_len(a);
    if (size == 2)
        sa(&a, false);
    else if (size == 3)
        sort_three(&a);
    else if (size <= 5)
        sort_five(&a, &b);
    else
        sort_main(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return (0);
}
