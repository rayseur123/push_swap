/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:02:22 by njooris           #+#    #+#             */
/*   Updated: 2025/02/03 11:30:47 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_stack(t_list_push **b, int val)
{
	t_list_push	*temp;

	temp = *b;
	while (temp)
	{
		if (temp->content == val)
		{
			return (1);
		}
		temp = temp->next;
	}
	return (-1);
}

int	last_val(t_list_push *a)
{
	while (a->next)
		a = a->next;
	return (a->content);
}

void	sort_for_three(t_list_push **a)
{
	if ((*a)->content < (*a)->next->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		lst_s(*a, 1);
		lst_r(a, 1);
	}
	else if ((*a)->content > (*a)->next->content
		&& (*a)->content < (*a)->next->next->content)
		lst_s(*a, 1);
	else if ((*a)->content < (*a)->next->content
		&& (*a)->content > (*a)->next->next->content)
	{
		lst_r(a, 1);
		lst_r(a, 1);
	}
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->next->next->content > (*a)->next->content)
		lst_r(a, 1);
	else if ((*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		lst_s(*a, 1);
		lst_rra(a, 1);
	}
}

void	manage_stack_b(t_list_push **a, t_list_push **b, int *val, int i)
{
	int	reverse;

	reverse = search_opti(b, i, i, i);
	while (*b && reverse != 0)
	{
		if (reverse <= 0)
			lst_rra(b, 2);
		else
			lst_r(b, 2);
		if ((*b)->content > *val && (*b)->content < i)
		{
			*val = (*b)->content;
			lst_p(b, a, 1);
			lst_r(a, 1);
		}
		reverse = search_opti(b, i, i, i);
	}
	lst_p(b, a, 1);
}

void	manage_stack_a(t_list_push **a, int *val, int size)
{
	lst_rra(a, 1);
	if (last_val(*a) != size)
		*val = last_val(*a);
	else
		*val = 0;
}
