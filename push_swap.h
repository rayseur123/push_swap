/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njooris <njooris@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:26:44 by njooris           #+#    #+#             */
/*   Updated: 2025/03/03 09:09:07 by njooris          ###   ########.fr       */
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
void		print_lst(t_list_push *a, t_data *data_a);
int			parsing(t_list_push **lst, char **av, t_data *data_a);
int			lst_atoi(const char *nptr, int *check);
void		free_all(t_list_push *lst);
int			check_double(t_list_push *lst, int i, t_data *data_a);
t_list_push	*lstnew(int content);
void		lstadd_back_circle(t_list_push **lst, t_list_push *new);

// sorting
void	sorting(t_list_push **a, t_data *data_a);
void	sort_three(t_list_push **a, t_data *data_a);

// presort
void	lstcpy_circle(t_list_push *src, t_list_push **to, t_data *data_a);
void	simplify_lst(t_list_push **a, t_data *data_a);
void	presort(t_list_push **a, t_list_push **b, t_data *data_a, t_data *data_b);

// utils
void	print_lst(t_list_push *a, t_data *data_a);
void	print_lst_reverse(t_list_push *a, t_data *data_a);
int		checker(t_list_push *lst, t_data *data_lst);
void	lstcpy_circle(t_list_push *src, t_list_push **to, t_data *data_a);
void	simplify_lst(t_list_push **a, t_data *data_a);

// search sort
int	search_opti(t_list_push **a, int start_min, int mid, int end_max, t_data *data_a, int val_max);

#endif
