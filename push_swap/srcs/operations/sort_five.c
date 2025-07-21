#include "../../inc/push_swap.h"

int		get_second_min(t_node **a)
{
	int		tmp;
	int		second_min;
	t_node	*head;

	head = (*a);
	while ((*a))
	{
		if ((*a)->nbr > (a*)->next->nbr)
		{
			tmp = (*a)->nbr;
			(*a)->nbr = (*a)->nbr->next;
			(*a)->next->nbr = tmp;
			(*a) = head;
		}
		else
			(*a) = (*a)->next;
	}
	second = (*a)->next->next->nbr;
	return (second);
}

void	sort_five(t_node **a)
{
	t_node		*max_node;
	t_node		*min_node;
	t_node		*second_min;

	min = get_min(*a);
	second_min = get_pivot(*a);
	pb(min, false);
	pb(second_min, false);
	sort_small_three(**a);
	//pa(	
}
