/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:09:27 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 17:15:24 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h" 

t_list_inst	*lstnew_bonus(char *content)
{
	t_list_inst	*lst;

	lst = malloc(sizeof(t_list_inst));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	return (lst);
}

t_list_inst	*lstlast_bonus(t_list_inst *lst)
{
	t_list_inst	*l;

	if (lst)
	{
		l = lst;
		while (l->next)
			l = l->next;
		return (l);
	}
	return (lst);
}

void	lstadd_back_bonus(t_list_inst **lst, t_list_inst *new)
{
	t_list_inst	*l;

	if (*lst)
	{
		l = lstlast_bonus(*lst);
		l->next = new;
	}
	else
		*lst = new;
}

void	free_all_lststring(t_list_inst *lst)
{
	t_list_inst	*temp;

	while (lst)
	{
		temp = lst;
		if (lst->next)
			lst = lst->next;
		else
			lst = NULL;
		free(temp->content);
		free(temp);
	}
}
