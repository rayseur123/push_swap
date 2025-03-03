/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:10:43 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 14:17:51 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list_push	*lst;
	t_data		data_a;

	data_a.len = ac - 1;
	lst = NULL;
	if (parsing(&lst, av, &data_a) == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	sorting(&lst, data_a);
	return (0);
}
