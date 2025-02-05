/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:03:33 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 15:28:36 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

int	check_instruction(char *str)
{
	if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "sb", 2)
		|| !ft_strncmp(str, "ss", 2) || !ft_strncmp(str, "pa", 2)
		|| !ft_strncmp(str, "pb", 2) || !ft_strncmp(str, "ra", 2)
		|| !ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2)
		|| !ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrb", 3)
		|| !ft_strncmp(str, "rrr", 3))
		return (1);
	return (0);
}

void	handle_swap(char *str, t_list_push **a, t_list_push **b)
{
	if (!ft_strncmp(str, "sa", 2))
		lst_s(*a, 3);
	else if (!ft_strncmp(str, "sb", 2))
		lst_s(*b, 3);
	else if (!ft_strncmp(str, "ss", 2))
	{
		lst_s(*a, 3);
		lst_s(*b, 3);
	}
}

void	handle_push(char *str, t_list_push **a, t_list_push **b)
{
	if (!ft_strncmp(str, "pa", 2))
		lst_p(b, a, 3);
	else if (!ft_strncmp(str, "pb", 2))
		lst_p(a, b, 3);
}

void	handle_rotate(char *str, t_list_push **a, t_list_push **b)
{
	if (!ft_strncmp(str, "ra", 2))
		lst_r(a, 3);
	else if (!ft_strncmp(str, "rb", 2))
		lst_r(b, 3);
	else if (!ft_strncmp(str, "rr", 2))
	{
		lst_r(a, 3);
		lst_r(b, 3);
	}
}

void	handle_reverse_rotate(char *str, t_list_push **a, t_list_push **b)
{
	if (!ft_strncmp(str, "rra", 3))
		lst_rra(a, 3);
	else if (!ft_strncmp(str, "rrb", 3))
		lst_rra(b, 3);
	else if (!ft_strncmp(str, "rrr", 3))
	{
		lst_rra(a, 3);
		lst_rra(b, 3);
	}
}
