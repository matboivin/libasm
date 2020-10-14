/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/14 16:55:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <assert.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "libasm_tests.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int fd, const void *buf, size_t count);
ssize_t				ft_read(int fd, void *buf, size_t count);
char				*ft_strdup(const char *s);
int					ft_atoi_base(const char *s, int base);
void				ft_list_push_front(t_list **lst, t_list *new_elem);
int					ft_lst_size(t_list *lst);
void				ft_lst_sort(t_list **lst, int (*cmp)());
void				ft_list_remove_if(t_list **lst, void *data_ref);

#endif
