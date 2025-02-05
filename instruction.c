/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:59 by njooris           #+#    #+#             */
/*   Updated: 2025/02/03 11:32:09 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	lst_s(t_list_push *lst, int i) // valid
{
	int	temp;

	if (!lst)
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	if (i == 1)
		ft_printf("sa\n");
	else if (i == 2)
		ft_printf("sb\n");
}

void	lst_ss(t_list_push *a, t_list_push *b)
{
	lst_s(a, 3);
	lst_s(b, 3);
	ft_printf("ss\n");
}

void	lst_p(t_list_push **from, t_list_push **to, int i)
{
	t_list_push	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = temp->next;
	temp->next = *to;
	*to = temp;
	if (i == 1)
		ft_printf("pa\n");
	else if (i == 2)
		ft_printf("pb\n");
}

void	lst_r(t_list_push **lst, int i)
{
	t_list_push	*temp;
	t_list_push	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	while (last->next)
		last = last->next;
	temp = *lst;
	*lst = (*lst)->next;
	last->next = temp;
	temp->next = NULL;
	if (i == 1)
		ft_printf("ra\n");
	else if (i == 2)
		ft_printf("rb\n");
}

void	lst_rr(t_list_push **a, t_list_push **b)
{
	lst_r(a, 3);
	lst_r(b, 3);
	ft_printf("rr\n");
}
