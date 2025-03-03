/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:58:04 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 14:08:52 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_up(t_list_push *lst, int start_min, int start_max, t_data *data_a, int val_max)
{
	int	i;

	i = 0;
	while (lst && (lst->content > start_max || lst->content < start_min
			|| lst->content >= val_max - 2)
		&& i < data_a->len && data_a->len > 3)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	search_down(t_list_push *lst, int start_min, int start_max, t_data *data_a, int val_max)
{
	int	i;

	i = 0;
	while (lst && (lst->content > start_max
			|| lst->content < start_min || lst->content >= val_max - 2) && i < data_a->len && data_a->len > 3)
	{
		lst = lst->pre;
		i++;
	}
	return (i * -1);
}

int	decide_result(int start_up, int start_down, int end_up, int end_down)
{
	if (start_up <= end_up && start_up <= (start_down * -1)
		&& start_up <= (end_down * -1))
		return (start_up);
	else if (end_up <= start_up && end_up <= (start_down * -1)
		&& end_up <= (end_down * -1))
		return (end_up);
	else if (start_down >= end_down && (start_down * -1) <= start_up
		&& (start_down * -1) <= end_up)
		return (start_down);
	return (end_down);
}

int	search_opti(int mid, int val_max, t_sort_datas *sd, t_search_data search)
{
	int			start_up;
	int			start_down;
	int			end_up;
	int			end_down;

	start_up = search_up(*sd->a, mid - search.part_bot, mid, sd->data_a, val_max);
	start_down = search_down(*sd->a, mid - search.part_bot, mid, sd->data_a, val_max);
	end_up = search_up(*sd->a, mid, mid + search.part_bot, sd->data_a, val_max);
	end_down = search_down(*sd->a, mid, mid + search.part_bot, sd->data_a, val_max);
	return (decide_result(start_up, start_down, end_up, end_down));
}
