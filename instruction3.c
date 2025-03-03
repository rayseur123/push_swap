/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:11:00 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 13:11:57 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	lst_r(t_list_push **a, t_data *data_a) // valid
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	data_a->first = *a;
}

void	lst_ra(t_list_push **a, t_data *data_a) // valid
{
	if (*a == NULL || (*a)->next == NULL || data_a->len < 2)
		return ;
	*a = (*a)->next;
	data_a->first = *a;
	ft_printf("ra\n");
}

void	lst_rb(t_list_push **b, t_data *data_b) // valid
{
	if (*b == NULL || (*b)->next == NULL || data_b->len < 2)
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

void	lst_ss(t_list_push *a, t_list_push *b)
{
	int	temp;

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
