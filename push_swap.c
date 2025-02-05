/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:43 by njooris           #+#    #+#             */
/*   Updated: 2025/02/04 16:19:49 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list_push	*lst;

	(void)ac;
	lst = NULL;
	if (parsing(&lst, av) == -1)
		return (-1);
	sorting(&lst);
	return (0);
}
