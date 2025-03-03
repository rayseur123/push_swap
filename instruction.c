/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:59 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 13:12:44 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	lst_sa(t_list_push *a)
{
	int	temp;

	if (!a)
		return ;
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	ft_printf("sa\n");
}

void	lst_sb(t_list_push *b)
{
	int	temp;

	if (!b)
		return ;
	temp = b->content;
	b->content = b->next->content;
	b->next->content = temp;
	ft_printf("sb\n");
}

void	lst_pa_manage(t_list_push **b, t_data *data_b)
{
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		(*b)->next->pre = (*b)->pre;
		(*b)->pre->next = (*b)->next;
		*b = (*b)->next;
	}
	data_b->first = *b;
	data_b->len--;
}

void	lst_pa(t_list_push **b, t_list_push **a, t_data *data_b, t_data *data_a)
{
	t_list_push	*temp;

	temp = *b;
	lst_pa_manage(b, data_b);
	if (*a == NULL)
	{
		*a = temp;
		(*a)->next = *a;
		(*a)->pre = *a;
	}
	else
	{
		temp->next = *a;
		temp->pre = (*a)->pre;
		(*a)->pre->next = temp;
		(*a)->pre = temp;
		*a = temp;
	}
	data_a->first = *a;
	data_a->len++;
	ft_printf("pa\n");
}

void	lst_pb(t_list_push **a, t_list_push **b, t_data *data_a, t_data *data_b)
{
	t_list_push	*temp;

	temp = *a;
	lst_pa_manage(a, data_a);
	if (*b == NULL)
	{
		*b = temp;
		(*b)->next = *b;
		(*b)->pre = *b;
	}
	else
	{
		temp->next = *b;
		temp->pre = (*b)->pre;
		(*b)->pre->next = temp;
		(*b)->pre = temp;
		*b = temp;
	}
	data_b->first = *b;
	data_b->len++;
	ft_printf("pb\n");
}
