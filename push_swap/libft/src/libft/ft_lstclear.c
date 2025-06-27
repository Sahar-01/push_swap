/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scheragh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:02:49 by scheragh          #+#    #+#             */
/*   Updated: 2024/12/23 12:12:25 by scheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if(!*lst)
		return ;
	while(*lst)
	{
		(*del)((*lst)->content);
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}
