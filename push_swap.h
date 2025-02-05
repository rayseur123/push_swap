/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:26:44 by njooris           #+#    #+#             */
/*   Updated: 2025/02/05 17:14:30 by njooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_list_push
{
	int					content;
	struct s_list_push	*next;
}	t_list_push;

typedef struct s_list_inst
{
	char					*content;
	struct s_list_inst		*next;
}	t_list_inst;

// instructions
void		lst_s(t_list_push *lst, int i);
void		lst_ss(t_list_push *a, t_list_push *b);
void		lst_p(t_list_push **from, t_list_push **to, int i);
void		lst_r(t_list_push **lst, int i);
void		lst_rr(t_list_push **a, t_list_push **b);
void		lst_rra(t_list_push **lst, int i);
void		lst_rrr(t_list_push *a, t_list_push *b);

// parsing
int			parsing(t_list_push **lst, char **av);
int			lst_atoi(const char *nptr, int *check);
void		free_all(t_list_push *lst);
int			check_double(t_list_push *lst, int i);
t_list_push	*lstnew(int content);
t_list_push	*lstlast(t_list_push *lst);
void		lstadd_back(t_list_push **lst, t_list_push *new);

// manage lst
int			lstsize(t_list_push *lst);
void		print_lst(t_list_push *lst);
int			search_min(t_list_push *lst);
void		lstcpy(t_list_push *src, t_list_push **to);

// searching
int			search_up(t_list_push *lst, int start_min, int start_max);
int			search_down(t_list_push *lst, int start_min, int start_max);
int			search_opti(t_list_push **a, int start_min, int mid, int end_max);

// pre-sorting
int			best_size_of_part(int size);
void		presort(t_list_push **a, t_list_push **b, int size);

// manage-stack
int			choose_stack(t_list_push **b, int val);
int			last_val(t_list_push *a);
void		sort_for_three(t_list_push **a);
void		manage_stack_b(t_list_push **a, t_list_push **b, int *val, int i);
void		manage_stack_a(t_list_push **a, int *val, int size);

// sorting
void		simplify_lst(t_list_push **a);
void		sort(t_list_push **a, t_list_push **b);
void		sorting(t_list_push **a);

// bonus
t_list_inst	*lstnew_bonus(char *content);
t_list_inst	*lstlast_bonus(t_list_inst *lst);
void		lstadd_back_bonus(t_list_inst **lst, t_list_inst *new);
int			check_instruction(char *str);
void		handle_swap(char *str, t_list_push **a, t_list_push **b);
void		handle_push(char *str, t_list_push **a, t_list_push **b);
void		handle_rotate(char *str, t_list_push **a, t_list_push **b);
void		handle_reverse_rotate(char *str, t_list_push **a, t_list_push **b);
t_list_inst	*lstnew_bonus(char *content);
t_list_inst	*lstlast_bonus(t_list_inst *lst);
void		lstadd_back_bonus(t_list_inst **lst, t_list_inst *new);
void		free_all_lststring(t_list_inst *lst);

#endif
