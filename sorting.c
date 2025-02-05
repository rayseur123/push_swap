/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:37:48 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 15:11:28 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplify_lst(t_list_push **a)
{
	t_list_push	*temp;
	t_list_push	*save_temp;
	t_list_push	*save_a;
	int			i;

	i = 0;
	lstcpy(*a, &temp);
	save_temp = temp;
	save_a = *a;
	while (save_a)
	{
		temp = save_temp;
		i = 1;
		while (temp)
		{
			if (save_a->content > temp->content)
				i++;
			temp = temp->next;
		}
		save_a->content = i;
		save_a = save_a->next;
	}
	free_all(save_temp);
}

void	sort(t_list_push **a, t_list_push **b)
{
	int	i;
	int	val;
	int	size;

	val = 0;
	size = lstsize(*b);
	i = size;
	while (*b || last_val(*a) != size)
	{
		if (choose_stack(b, i) == 1)
			manage_stack_b(a, b, &val, i);
		else if (last_val(*a) == i)
			manage_stack_a(a, &val, size);
		i--;
	}
}

int	checker(t_list_push *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sorting(t_list_push **a)
{
	t_list_push	*b;
	int			size;

	simplify_lst(a);
	size = lstsize(*a);
	b = NULL;
	if (checker(*a) != 1 && size == 3)
		sort_for_three(a);
	else if (checker(*a) != 1)
	{
		presort(a, &b, size);
		sort(a, &b);
	}
	free_all(*a);
	free_all(b);
	return ;
}
