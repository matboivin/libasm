/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:17:57 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 19:08:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libasm.h"

/*
** This function counts the number of nodes in a list
**
** lst: Pointer to the first node of a list
**
** returns: The length of the list
*/

int			ft_list_size(t_list *begin_list)
{
	int		size;

	size = 0;
	if (begin_list)
	{
		while (begin_list)
		{
			size++;
			begin_list = begin_list->next;
		}
	}
	return (size);
}
