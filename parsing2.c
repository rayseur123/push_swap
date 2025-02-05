/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:54:54 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 18:22:58 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

void	lstadd_back(t_list_push **lst, t_list_push *new)
{
	t_list_push	*l;

	if (*lst)
	{
		l = lstlast(*lst);
		l->next = new;
	}
	else
		*lst = new;
}

int	parsing(t_list_push **lst, char **av)
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
		if (check == 0 || !lst_add || !check_double(*lst, val))
		{
			write(2, "Error\n", 6);
			free_all(*lst);
			free(lst_add);
			return (-1);
		}
		lstadd_back(lst, lst_add);
		i++;
	}
	return (0);
}
