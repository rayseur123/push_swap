/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:13:30 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 17:15:25 by njooris          ###   ########.fr       */
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

void	browse_lst(t_list_push	*temp, int count,
		t_data *data_a, t_list_push	*save_a)
{
	int			count2;
	t_list_push	*save_temp;
	int			i;

	save_temp = temp;
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

void	simplify_lst(t_list_push **a, t_data *data_a)
{
	t_list_push	*temp;
	t_list_push	*save_a;
	int			count;

	count = 0;
	lstcpy_circle(*a, &temp, data_a);
	save_a = *a;
	browse_lst(temp, count, data_a, save_a);
}
