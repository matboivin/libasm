/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 14:13:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		ft_list_remove_if_c(t_list **lst, void *data_ref)
{
	t_list	*to_free;

	if (!lst || !data_ref)
		return ;
	if (*lst)
	{
		to_free = NULL;
		while (*lst)
		{
			if ((*lst)->data == data_ref)
			{
				to_free = *lst;
				*lst = (*lst)->next;
				free(to_free);
			}
			else
				*lst = (*lst)->next;
		}
	}
}
