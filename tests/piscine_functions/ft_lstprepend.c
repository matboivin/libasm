/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:36:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 19:07:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

/*
** This function prepends the new node to the list
**
** lst: The address of a pointer to the first node of a list
** new_elem: The address of a pointer to the node to add to the list
*/

void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_list_new(data);
	if (begin_list && new_elem)
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
}
