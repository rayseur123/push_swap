/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:54:54 by njooris           #+#    #+#             */
/*   Updated: 2025/02/20 16:57:36 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

void	lstadd_back_circle(t_list_push **lst, t_list_push *new)
{
	if (*lst && !(*lst)->next)
	{
		(*lst)->next = new;
		(*lst)->pre = new;
		new->next = *lst;
		new->pre = *lst;
	}
	else if (*lst)
	{
		(*lst)->pre->next = new;
		new->pre = (*lst)->pre;
		(*lst)->pre = new;
		new->next = (*lst);
	}
	else
		*lst = new;
}

int	parsing(t_list_push **lst, char **av, t_data *data_a)
{
	int			val;
	int			i;
	int			check;
	t_list_push	*lst_add;

	check = 0;
	i = 1;
	while (av && av[i])
	{
		val = lst_atoi(av[i], &check);
		lst_add = lstnew(val);
		if (check == 0 || !lst_add || !check_double(*lst, val, data_a))
		{
			free_all(*lst);
			free(lst_add);
			return (-1);
		}
		lstadd_back_circle(lst, lst_add);
		i++;
	}
	data_a->first = *lst;
	return (0);
}
