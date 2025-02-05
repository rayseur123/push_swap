/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:22:03 by njooris           #+#    #+#             */
/*   Updated: 2025/02/03 14:01:41 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

int	lst_atoi(const char *nptr, int *check)
{
	int				x;
	long int		val;
	int				negativ;

	val = 0;
	negativ = 1;
	x = 0;
	*check = 1;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		negativ *= 44 - nptr[x];
		x++;
	}
	if (x > 1)
		*check = 0;
	while (nptr[x] != '\0')
	{
		if ((10 * val + (nptr[x] - '0')) / 10 != val
			|| val > 2147483647 || val < -2147483648
			|| !ft_isdigit(nptr[x]))
			*check = 0;
		val = 10 * val + (nptr[x++] - '0');
	}
	return (val * negativ);
}

void	free_all(t_list_push *lst)
{
	t_list_push	*temp;

	while (lst)
	{
		temp = lst;
		if (lst->next)
			lst = lst->next;
		else
			lst = NULL;
		free(temp);
	}
}

int	check_double(t_list_push *lst, int i)
{
	while (lst)
	{
		if (lst->content == i)
			return (0);
		lst = lst->next;
	}
	return (1);
}

t_list_push	*lstnew(int content)
{
	t_list_push	*lst;

	lst = malloc(sizeof(t_list_push));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}

t_list_push	*lstlast(t_list_push *lst)
{
	t_list_push	*l;

	if (lst)
	{
		l = lst;
		while (l->next)
			l = l->next;
		return (l);
	}
	return (lst);
}
