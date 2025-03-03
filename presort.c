/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:59:55 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 14:14:02 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_size_of_part(int size)
{
	int	square;

	square = 1;
	while (square * square < size)
		square++;
	return (square);
}

void	presort(t_sort_datas *sd)
{
	t_search_data	search;
	int				mid;
	int				val_max;

	val_max = sd->data_a->len;
	search.part_bot = best_size_of_part(sd->data_a->len);
	search.part_top = search.part_bot;
	mid = sd->data_a->len / 2;
	while ((*sd->a) && sd->data_a->len > 3)
	{
		if ((*sd->a)->content >= mid && (*sd->a)->content <= mid + search.part_top++
			&& (*sd->a)->content < val_max - 2)
			lst_pb(sd->a, sd->b, sd->data_a, sd->data_b);
		else if ((*sd->a)->content < mid && (*sd->a)->content >= mid - search.part_bot++
			&& (*sd->a)->content < val_max - 2)
		{
			lst_pb(sd->a, sd->b, sd->data_a, sd->data_b);
			lst_rb(sd->b, sd->data_b);
		}
		while ((*sd->a) && search_opti(mid, val_max, sd, search) != 0)
		{
			if (search_opti(mid, val_max, sd, search) <= 0)
				lst_rra(sd->a, sd->data_a);
			else if (search_opti(mid, val_max, sd, search) >= 0)
				lst_ra(sd->a, sd->data_a);
		}
	}
	sort_three(sd->a, sd->data_a);
}
