/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 15:49:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
** Mandatory functions
*/

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int fd, const void *buf, size_t count);
ssize_t				ft_read(int fd, void *buf, size_t count);
char				*ft_strdup(const char *s);
int					ft_atoi_base(const char *s, int base);

/*
** Bonus functions
*/

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int					ft_list_size(t_list *begin_list);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_remove_if(
	t_list **begin_list, void *data_ref, int (*cmp)());

#endif
