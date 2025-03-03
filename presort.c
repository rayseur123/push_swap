/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:59:55 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 13:37:00 by njooris          ###   ########.fr       */
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

void	presort(t_list_push **a, t_list_push **b,
				t_data *data_a, t_data *data_b)
{
	int	part_bot;
	int	mid;
	int	part_top;
	int	val_max;

	val_max = data_a->len;
	part_bot = best_size_of_part(data_a->len);
	part_top = part_bot;
	mid = data_a->len / 2;
	while (*a && data_a->len > 3)
	{
		if ((*a)->content >= mid && (*a)->content <= mid + part_top++
			&& (*a)->content < val_max - 2)
			lst_pb(a, b, data_a, data_b);
		else if ((*a)->content < mid && (*a)->content >= mid - part_bot++
			&& (*a)->content < val_max - 2)
		{
			lst_pb(a, b, data_a, data_b);
			lst_rb(b, data_b);
		}
		while ((*a) && search_opti(a, mid - part_bot, mid,
				mid + part_top, data_a, val_max) != 0)
		{
			if (search_opti(a, mid - part_bot, mid,
					mid + part_top, data_a, val_max) <= 0)
				lst_rra(a, data_a);
			else if (search_opti(a, mid - part_bot,
					mid, mid + part_top, data_a, val_max) >= 0)
				lst_ra(a, data_a);
		}
	}
	sort_three(a, data_a);
}
