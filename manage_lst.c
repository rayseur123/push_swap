/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:56:24 by njooris           #+#    #+#             */
/*   Updated: 2025/02/03 12:07:34 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_list_push *lst)
{
	int		count;

	count = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			count++;
		}
	}
	return (count);
}

void	print_lst(t_list_push *lst)
{
	while (lst)
	{
		ft_printf("%d", lst->content);
		if (lst->next)
			ft_printf("->");
		lst = lst->next;
	}
	ft_printf("\n");
}

int	search_min(t_list_push *lst)
{
	int	i;

	i = lst->content;
	while (lst && lst->next)
	{
		if (i > lst->next->content)
			i = lst->next->content;
		lst = lst->next;
	}
	return (i);
}

void	lstcpy(t_list_push *src, t_list_push **to)
{
	(*to) = lstnew(src->content);
	while (src->next)
	{
		src = src->next;
		lstadd_back(to, lstnew(src->content));
	}
}
