/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 13:50:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

char		*ft_strnew(size_t size)
{
	char	*result;

	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	bzero(result, size + 1);
	return (result);
}

void		ft_strdel(char **to_free)
{
	if (to_free && *to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

t_list		*ft_list_new(void *p_data)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->data = p_data;
	result->next = NULL;
	return (result);
}

void		ft_list_del(t_list **node)
{
	t_list	*cursor;
	t_list	*next_list;

	if (!node)
		return ;
	if (*node)
	{
		cursor = *node;
		while (cursor)
		{
			next_list = cursor->next;
			free(cursor);
			cursor = next_list;
		}
		*node = NULL;
	}
}

void		ft_list_push_back(t_list **head, t_list *new_node)
{
	t_list	*cursor;

	if (!head || !new_node)
		return ;
	if (*head)
	{
		cursor = *head;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_node;
	}
	else
		*head = new_node;
}

void		ft_list_print(t_list *lst)
{
	int		i;

	if (lst)
	{
		i = 1;
		while (lst)
		{
			printf("node %d -> data: \"%s\"\n", i, lst->data);
			lst = lst->next;
			i++;
		}
	}
	else
		printf("NULL\n");
}
