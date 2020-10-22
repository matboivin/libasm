/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/22 17:59:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_LIST_H
# define LIBASM_LIST_H

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int					ft_list_size(t_list *lst);
void				ft_list_push_front(t_list **lst, t_list *new_elem);
void				ft_lst_sort(t_list **lst, int (*cmp)());
void				ft_list_remove_if(t_list **lst, void *data_ref);

/*
** Test bonus functions
*/

t_list				*ft_list_new(void *p_data);
void				ft_list_del(t_list **node);
void				ft_list_push_back(t_list **head, t_list *new_node);

#endif
