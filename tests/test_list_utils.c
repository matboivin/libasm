/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:15:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

/*
** List utils
*/

t_node		*ft_list_new(void *p_content)
{
	t_node	*result;

	result = malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->content = p_content;
	result->next = NULL;
	return (result);
}

void		ft_list_del(t_node **node)
{
	t_node	*cursor;
	t_node	*next_node;

	if (!node)
		return ;
	if (*node)
	{
		cursor = *node;
		while (cursor)
		{
			next_node = cursor->next;
			free(cursor);
			cursor = next_node;
		}
		*node = NULL;
	}
}

void		ft_list_append(t_node **head, t_node *new_node)
{
	t_node	*cursor;

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

void		ft_list_print(t_node *node)
{
	int		i;

	if (node)
	{
		i = 1;
		while (node)
		{
			printf("node %d -> content: \"%s\"\n", i, (char *)node->content);
			node = node->next;
			i++;
		}
	}
	else
		printf("NULL\n");
}
