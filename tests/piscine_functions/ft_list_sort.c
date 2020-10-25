/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:20:19 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 19:08:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

/*
** This function sorts the list’s data by ascending order by comparing two
** nodes thanks to a function that can compare their data
**
** lst: Pointer to the first node of a list
** cmp: The comparison function
*/

void		ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*cursor;
	t_list	*next_node;
	t_list	*next_data;

	if (!begin_list || !cmp)
		return ;
	if (*begin_list)
	{
		cursor = *begin_list;
		while (cursor)
		{
			next_node = cursor->next;
			while (next_node)
			{
				if (cmp(cursor->data, next_node->data) > 0)
				{
					next_data = cursor->data;
					cursor->data = next_node->data;
					next_node->data = next_data;
				}
				next_node = next_node->next;
			}
			cursor = cursor->next;
		}
	}
}
