/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:59:55 by njooris           #+#    #+#             */
/*   Updated: 2025/02/03 11:17:02 by njooris          ###   ########.fr       */
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

void	presort(t_list_push **a, t_list_push **b, int size)
{
	int	part_bot;
	int	mid;
	int	part_top;

	part_bot = best_size_of_part(size);
	part_top = part_bot;
	mid = size / 2;
	while (*a)
	{
		if ((*a)->content >= mid && (*a)->content <= mid + part_top++)
			lst_p(a, b, 2);
		else if ((*a)->content < mid && (*a)->content >= mid - part_bot++)
		{
			lst_p(a, b, 2);
			lst_r(b, 2);
		}
		while ((*a) && search_opti(a, mid - part_bot, mid, mid + part_top) != 0)
		{
			if (search_opti(a, mid - part_bot, mid, mid + part_top) <= 0)
				lst_rra(a, 1);
			else if (search_opti(a, mid - part_bot, mid, mid + part_top) >= 0)
				lst_r(a, 1);
		}
	}
}
