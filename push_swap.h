/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:26:44 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 14:09:10 by njooris          ###   ########.fr       */
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
	struct s_list_push	*pre;
}	t_list_push;

typedef struct s_data
{
	struct s_list_push	*first;
	int					len;
}	t_data;

typedef struct s_sort_datas
{
	struct s_list_push	**a;
	struct s_list_push	**b;
	struct s_data		*data_a;
	struct s_data		*data_b;
}	t_sort_datas;

typedef struct s_search_data
{
	int	part_bot;
	int	part_top;
}	t_search_data;

// instructions
void		lst_sa(t_list_push *a);
void		lst_sb(t_list_push *b);
void		lst_ss(t_list_push *a, t_list_push *b);
void		lst_pa(t_list_push **b, t_list_push **a, t_data *data_b, t_data *data_a);
void		lst_pb(t_list_push **a, t_list_push **b, t_data *data_a, t_data *data_b);
void		lst_ra(t_list_push **a, t_data *data_a);
void		lst_rb(t_list_push **b, t_data *data_b);
void		lst_r(t_list_push **a, t_data *data_a);
void		lst_rr(t_list_push **a, t_list_push **b, t_data *data_a, t_data *data_b);
void		lst_rra(t_list_push **a, t_data *data_a);
void		lst_rrb(t_list_push **b, t_data *data_b);
void		lst_rrr(t_list_push **a, t_data *data_a, t_list_push **b, t_data *data_b);

// parsing
int			parsing(t_list_push **lst, char **av, t_data *data_a);
int			lst_atoi(const char *nptr, int *check);
void		free_all(t_list_push *lst);
int			check_double(t_list_push *lst, int i, t_data *data_a);
t_list_push	*lstnew(int content);
void		lstadd_back_circle(t_list_push **lst, t_list_push *new);

// sorting
void		sorting(t_list_push **a, t_data *data_a);
void		sort_three(t_list_push **a, t_data *data_a);
int			search_path(t_list_push *b, int val);
int			choose_manage(t_list_push *b, int val, t_data *data_b);

// presort
void		lstcpy_circle(t_list_push *src, t_list_push **to, t_data *data_a);
void		simplify_lst(t_list_push **a, t_data *data_a);
void		presort(t_sort_datas *sort_datas);

// utils
int			checker(t_list_push *lst, t_data *data_lst);
void		lstcpy_circle(t_list_push *src, t_list_push **to, t_data *data_a);
void		simplify_lst(t_list_push **a, t_data *data_a);

// search sort
int	search_opti(int mid, int val_max, t_sort_datas *sd, t_search_data search);

#endif
