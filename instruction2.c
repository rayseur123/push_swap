/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:39 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 13:13:24 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	lst_rra(t_list_push **a, t_data *data_a)
{
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->pre;
	data_a->first = *a;
	ft_printf("rra\n");
}

void	lst_rrb(t_list_push **b, t_data *data_b)
{
	if (*b == NULL || (*b)->next == NULL)
		return ;
	*b = (*b)->pre;
	data_b->first = *b;
	ft_printf("rrb\n");
}

void	lst_rrr(t_list_push **a, t_data *data_a,
				t_list_push **b, t_data *data_b)
{
	if (*a == NULL || (*a)->next == NULL
		|| *b == NULL || (*b)->next == NULL)
		return ;
	*a = (*a)->pre;
	data_a->first = *a;
	*b = (*b)->next;
	data_b->first = *b;
	ft_printf("rrr\n");
}
