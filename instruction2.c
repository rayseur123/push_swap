/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:39 by njooris           #+#    #+#             */
/*   Updated: 2025/02/03 11:07:19 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	lst_rra(t_list_push **lst, int i)
{
	t_list_push	*temp;
	t_list_push	*first;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	while (first->next && first->next->next)
		first = first->next;
	temp = first->next;
	first->next = NULL;
	temp->next = *lst;
	*lst = temp;
	if (i == 1)
		ft_printf("rra\n");
	else if (i == 2)
		ft_printf("rrb\n");
}

void	lst_rrr(t_list_push *a, t_list_push *b)
{
	lst_rra(&a, 3);
	lst_rra(&b, 3);
	ft_printf("rrr\n");
}
