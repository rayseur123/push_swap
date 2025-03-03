/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:48 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 11:04:32 by njooris          ###   ########.fr       */
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

int		choose_manage(t_list_push *b, int val, t_data *data_b)
{
	int		i;

	i = 0;
	while (i < data_b->len)
	{
		if(b->content == val)
			return (1);
		b = b->next;
		i++;
	}
	return (0);
}

int		search_path(t_list_push *b, int val)
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
	if(count2 * -1 < count1)
		return (count2);
	return (count1);
}

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
	if((*a)->pre->content != max)
		*val_mid = (*a)->pre->content;
	else
		*val_mid = 0;
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
			manage_b(sort_datas,  val_search, &val_mid);
			lst_pa(sort_datas->b, sort_datas->a, sort_datas->data_b, sort_datas->data_a);
		}
		else
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
void	print_lst(t_list_push *a, t_data *data_a)
{
	int	count;

	count = 0;
	if(!a)
		ft_printf("null\n");
	while (count != data_a->len)
	{
		ft_printf("%d->", a->content);
		a = a->next;
		count++;
	}
	ft_printf("\n");
}

void	print_lst_reverse(t_list_push *a, t_data *data_a)
{
	int	count;

	count = 0;
	if(!a)
		ft_printf("null\n");
	while(count != data_a->len)
	{
		ft_printf("%d->", a->content);
		a = a->pre;
		count++;
	}
	ft_printf("\n");
}

void	sorting(t_list_push **a, t_data *data_a)
{
	t_list_push	*b;
	t_data		*data_b;
	t_sort_datas	*sort_datas;

	simplify_lst(a, data_a);
	b = NULL;
	data_b = malloc(sizeof(t_data));
	data_b->first = NULL;
	data_b->len = 0;
	sort_datas = malloc(sizeof(t_sort_datas));
	if (checker(*a, data_a) != 1)
	{
		presort(a, &b, data_a, data_b);
		sort_datas->a = a;
		sort_datas->b = &b;
		sort_datas->data_a = data_a;
		sort_datas->data_b = data_b;
		sort(sort_datas);
	}
	free_all(*a);
	free_all(b);
	free(data_b);
	free(data_a);
	free(sort_datas);
	return ;
}
