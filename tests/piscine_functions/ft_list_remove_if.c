/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 22:08:20 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 19:08:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

/*
** This function erases off the list all nodes, whose data is "equal" to the
** reference data
**
** lst: Pointer to the first node of a list
** data_ref: The data to be compared to the data
*/

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cursor;
	t_list	*to_free;

	if (!begin_list || !data_ref || !cmp)
		return ;
	cursor = NULL;
	to_free = NULL;
	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		to_free = *begin_list;
		*begin_list = (*begin_list)->next;
		free(to_free);
	}
	cursor = *begin_list;
	while (cursor)
	{
		if (cursor->next && !cmp(cursor->next->data, data_ref))
		{
			to_free = cursor->next;
			cursor->next = to_free->next;
			free(to_free);
		}
		cursor = cursor->next;
	}
}
