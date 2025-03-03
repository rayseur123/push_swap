/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:17:52 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 12:18:22 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstcpy_circle(t_list_push *src, t_list_push **to, t_data *data_a)
{
	int	count;

	count = 0;
	(*to) = lstnew(src->content);
	while (count != data_a->len)
	{
		src = src->next;
		lstadd_back_circle(to, lstnew(src->content));
		count++;
	}
}

void	simplify_lst(t_list_push **a, t_data *data_a)
{
	t_list_push	*temp;
	t_list_push	*save_temp;
	t_list_push	*save_a;
	int			i;
	int			count;
	int			count2;

	count = 0;
	lstcpy_circle(*a, &temp, data_a);
	save_temp = temp;
	save_a = *a;
	while (count != data_a->len)
	{
		count2 = 0;
		temp = save_temp;
		i = 1;
		while (count2 != data_a->len)
		{
			if (save_a->content > temp->content)
				i++;
			temp = temp->next;
			count2++;
		}
		save_a->content = i;
		save_a = save_a->next;
		count++;
	}
	free_all(save_temp);
}

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
