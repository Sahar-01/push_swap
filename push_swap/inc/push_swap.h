/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:57:44 by scheragh          #+#    #+#             */
/*   Updated: 2025/07/21 11:38:40 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/inc/libft.h"

/* ======== Node structure ======== */

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* ======== Libft used functions ======== */

int		ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);

/* ======== Custom list utils for t_node ======== */

t_node	*ps_lstnew(int value);
void	ps_lstadd_back(t_node **stack, t_node *new);

/* ======== Stack utilities ======== */

t_node	*find_last(t_node *stack);
t_node	*find_first(t_node *stack);
t_node	*get_max(t_node *stack);
t_node	*get_min(t_node *stack);
int		stack_len(t_node *stack);
bool	sorted(t_node *stack);
void	free_stack(t_node **stack);
void	index_stack(t_node **stack);
void	init_stack(t_node **a, char **argv);
void	sort_three(t_node **a);
void sort_five(t_node **a, t_node **b);

/* ======== Operations ======== */

void	sa(t_node **a, bool printed);
void	sb(t_node **b, bool printed);
void	ss(t_node **a, t_node **b, bool printed);
void	pa(t_node **a, t_node **b, bool printed);
void	pb(t_node **b, t_node **a, bool printed);
void	ra(t_node **a, bool printed);
void	rb(t_node **b, bool printed);
void	rr(t_node **a, t_node **b, bool printed);
void	rra(t_node **a, bool printed);
void	rrb(t_node **b, bool printed);
void	rrr(t_node **a, t_node **b, bool printed);

#endif
