/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:48 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 13:40:30 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_b(t_sort_datas *sort_datas, int val_search, int *val_mid)
{
	int	path;

	path = search_path(*sort_datas->b, val_search);
	while ((*sort_datas->b) && path != 0)
	{
		if (*val_mid < (*sort_datas->b)->content && *val_mid != val_search)
		{
			*val_mid = (*sort_datas->b)->content;
			lst_pa(sort_datas->b, sort_datas->a, sort_datas->data_b, sort_datas->data_a);
			lst_ra(sort_datas->a, sort_datas->data_a);
			if (path > 0)
				path--;
		}
		if ((*sort_datas->b) && path < 0)
		{
			lst_rrb(sort_datas->b, sort_datas->data_b);
			path++;
		}
		else if ((*sort_datas->b) && path > 0)
		{
			lst_rb(sort_datas->b, sort_datas->data_b);
			path--;
		}
	}
}

void	manage_a(t_list_push **a, t_data *data_a, int *val_mid, int max)
{
	lst_rra(a, data_a);
	if ((*a)->pre->content != max)
		*val_mid = (*a)->pre->content;
	else
		*val_mid = 0;
}

void	sort(t_sort_datas *sort_datas)
{
	int	val_mid;
	int	val_search;
	int	max;

	val_mid = 0;
	val_search = sort_datas->data_b->len + sort_datas->data_a->len;
	max = val_search;
	while (sort_datas->data_b->len != 0 && val_search != 0)
	{
		if (choose_manage(*sort_datas->b, val_search, sort_datas->data_b) == 1)
		{
			manage_b(sort_datas, val_search, &val_mid);
			lst_pa(sort_datas->b, sort_datas->a, sort_datas->data_b, sort_datas->data_a);
		}
		else if (!((*sort_datas->a)->pre->content == sort_datas->data_a->len + sort_datas->data_b->len))
		{
			manage_a(sort_datas->a, sort_datas->data_a, &val_mid, max);
		}
		val_search--;
	}
	while (checker(*sort_datas->a, sort_datas->data_a) != 1)
		manage_a(sort_datas->a, sort_datas->data_a, &val_mid, max);
}

int	checker(t_list_push *lst, t_data *data_lst)
{
	while (lst && lst->next && lst->next != data_lst->first)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sorting(t_list_push **a, t_data *data_a)
{
	t_list_push		*b;
	t_data			*data_b;
	t_sort_datas	*sort_datas;

	simplify_lst(a, data_a);
	b = NULL;
	data_b = malloc(sizeof(t_data));
	data_b->first = NULL;
	data_b->len = 0;
	sort_datas = malloc(sizeof(t_sort_datas));
	if (checker(*a, data_a) != 1)
	{
		sort_datas->a = a;
		sort_datas->b = &b;
		sort_datas->data_a = data_a;
		sort_datas->data_b = data_b;
		presort(sort_datas);
		sort(sort_datas);
	}
	free_all(*a);
	free_all(b);
	free(data_b);
	free(data_a);
	free(sort_datas);
	return ;
}
