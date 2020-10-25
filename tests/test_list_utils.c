/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 16:26:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

/*
** List utils
*/

t_list			*ft_list_new(void *p_data)
{
	t_list		*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->data = p_data;
	result->next = NULL;
	return (result);
}

void			ft_list_del(t_list **begin_list)
{
	t_list		*cursor;
	t_list		*next_node;

	if (!begin_list)
		return ;
	if (*begin_list)
	{
		cursor = *begin_list;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor);
			cursor = next_node;
		}
		*begin_list = NULL;
	}
}

void			ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*cursor;

	if (!begin_list || !data)
		return ;
	if (*begin_list)
	{
		cursor = *begin_list;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = ft_list_new(data);
	}
	else
		*begin_list = ft_list_new(data);
}

void			ft_list_print(t_list *node)
{
	int			i;

	if (node)
	{
		i = 1;
		while (node)
		{
			printf("node %d -> data: \"%s\"\n", i, node->data);
			node = node->next;
			i++;
		}
	}
	else
		printf("NULL\n");
}

/*
** Write a function called ft_list_remove_if that removes from the passed list
** any element the data of which is "equal" to the reference data.
** It will be declared as follows :
** void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
** cmp takes two void* and returns 0 when both parameters are equal.
*/

int				data_cmp(void *data, void *data_ref)
{
	return ((*(int *)data) - (*(int *)data_ref));
}

void			ft_list_remove_if_c(
	t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*to_free;

	if (!begin_list || !data_ref || !cmp)
		return ;
	to_free = NULL;
	while (*begin_list)
	{
		if (*begin_list && !cmp((*begin_list)->data, data_ref))
		{
			to_free = *begin_list;
			*begin_list = (*begin_list)->next;
			free(to_free);
		}
		else
			*begin_list = (*begin_list)->next;
	}
}
