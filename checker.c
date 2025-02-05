/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:35:35 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 18:33:27 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft.h" 

void	apply_instr(char *str, t_list_push **a, t_list_push **b)
{
	if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "sb", 2)
		|| !ft_strncmp(str, "ss", 2))
		handle_swap(str, a, b);
	else if (!ft_strncmp(str, "pa", 2) || !ft_strncmp(str, "pb", 2))
		handle_push(str, a, b);
	else if (!ft_strncmp(str, "ra", 2) || !ft_strncmp(str, "rb", 2)
		|| !ft_strncmp(str, "rr", 2))
		handle_rotate(str, a, b);
	else if (!ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrb", 3)
		|| !ft_strncmp(str, "rrr", 3))
		handle_reverse_rotate(str, a, b);
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

void	manage_instr(t_list_push **a, t_list_inst *lst_instr)
{
	t_list_push	*b;
	t_list_inst	*save;

	save = lst_instr;
	b = NULL;
	while (lst_instr)
	{
		apply_instr(lst_instr->content, a, &b);
		lst_instr = lst_instr->next;
	}
	if (checker(*a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all_lststring(save);
	free_all(*a);
	free_all(b);
}

int	process_instructions(t_list_inst **lst_instr)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (str)
		{
			if (*lst_instr && check_instruction(str))
				lstadd_back_bonus(lst_instr, lstnew_bonus(str));
			else if (check_instruction(str))
				*lst_instr = lstnew_bonus(str);
			else
			{
				free(str);
				write(2, "Error\n", 6);
				return (-1);
			}
			str = NULL;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list_push	*a;
	t_list_inst	*lst_instr;

	(void)ac;
	lst_instr = NULL;
	a = NULL;
	if (parsing(&a, av) == -1)
		return (-1);
	if (process_instructions(&lst_instr) == -1)
	{
		free_all_lststring(lst_instr);
		free_all(a);
		return (0);
	}
	manage_instr(&a, lst_instr);
	return (0);
}
