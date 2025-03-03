/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:59 by njooris           #+#    #+#             */
/*   Updated: 2025/02/19 16:30:50 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	lst_sa(t_list_push *a) // valid
{
	int temp;

	if (!a)
		return ;
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	ft_printf("sa\n");
}

void	lst_sb(t_list_push *b) // valid
{
	int temp;

	if (!b)
		return ;
	temp = b->content;
	b->content = b->next->content;
	b->next->content = temp;
	ft_printf("sb\n");
}

void	lst_ss(t_list_push *a, t_list_push *b) // valid
{
	int temp;
	if (!a || !b)
		return ;
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
	temp = b->content;
	b->content = b->next->content;
	b->next->content = temp;
	ft_printf("ss\n");
}

void lst_pa(t_list_push **b, t_list_push **a, t_data *data_b, t_data *data_a) // valid
{
    t_list_push *temp;

    temp = *b;
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

void lst_pb(t_list_push **a, t_list_push **b, t_data *data_a, t_data *data_b) // valid
{
    t_list_push *temp;

    temp = *a;
    if (*a == (*a)->next)
        *a = NULL;
    else
	{
        (*a)->next->pre = (*a)->pre;
        (*a)->pre->next = (*a)->next;
        *a = (*a)->next;
    }
    data_a->first = *a;
    data_a->len--;
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

void	lst_r(t_list_push **a, t_data *data_a) // valid
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	data_a->first = *a;
}

void	lst_ra(t_list_push **a, t_data *data_a) // valid
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	data_a->first = *a;
	ft_printf("ra\n");
}

void	lst_rb(t_list_push **b, t_data *data_b) // valid
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	*b = (*b)->next;
	data_b->first = *b;
	ft_printf("rb\n");
}

void	lst_rr(t_list_push **a, t_list_push **b, t_data *data_a, t_data *data_b) // valid
{
	if (*b == NULL || (*b)->next == NULL
		|| *a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	data_a->first = *a;
	*b = (*b)->next;
	data_b->first = *b;
	ft_printf("rr\n");
}
