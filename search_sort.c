/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:58:04 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 16:58:10 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_up(t_list_push *lst, int start_min, int start_max)
{
	int	i;

	i = 0;
	while (lst && (lst->content > start_max
			|| lst->content < start_min) && i < lstsize(lst))
	{
		lst_r(&lst, 3);
		i++;
	}
	free_all(lst);
	return (i);
}

int	search_down(t_list_push *lst, int start_min, int start_max)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lst && i < lstsize(lst))
	{
		if (lst && lst->content >= start_min && lst->content <= start_max)
			j = i;
		lst_r(&lst, 3);
		i++;
	}
	i = (i - j) * -1;
	free_all(lst);
	return (i);
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

int	search_opti(t_list_push **a, int start_min, int mid, int end_max)
{
	int			start_up;
	int			start_down;
	int			end_up;
	int			end_down;
	t_list_push	*lst;

	lstcpy(*a, &lst);
	start_up = search_up(lst, start_min, mid);
	lstcpy(*a, &lst);
	start_down = search_down(lst, start_min, mid);
	lstcpy(*a, &lst);
	end_up = search_up(lst, mid, end_max);
	lstcpy(*a, &lst);
	end_down = search_down(lst, mid, end_max);
	return (decide_result(start_up, start_down, end_up, end_down));
}
