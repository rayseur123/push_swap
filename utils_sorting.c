/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:17:52 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 17:15:12 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_manage(t_list_push *b, int val, t_data *data_b)
{
	int		i;

	i = 0;
	while (i < data_b->len)
	{
		if (b->content == val)
			return (1);
		b = b->next;
		i++;
	}
	return (0);
}

int	search_path(t_list_push *b, int val)
{
	t_list_push	*temp;
	int			count1;
	int			count2;

	count1 = 0;
	count2 = 0;
	temp = b;
	while (val != b->content)
	{
		count1++;
		b = b->next;
	}
	while (val != temp->content)
	{
		count2--;
		temp = temp->pre;
	}
	if (count2 * -1 < count1)
		return (count2);
	return (count1);
}

void	sort_three(t_list_push **a, t_data *data_a)
{
	if ((*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		lst_sa((*a));
		lst_ra(a, data_a);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		lst_sa((*a));
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
	{
		lst_ra(a, data_a);
		lst_ra(a, data_a);
	}
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->next->next->content > (*a)->next->content)
		lst_ra(a, data_a);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		lst_sa((*a));
		lst_rra(a, data_a);
	}
}
