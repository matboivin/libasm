/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:32:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 16:42:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

// static void		ft_list_remove_if_c(
// 	t_list **begin_list, void *data_ref, int (*cmp)())
// {
// 	t_list	*to_free;

// 	if (!begin_list || !data_ref || !cmp)
// 		return ;
// 	to_free = NULL;
// 	while (*begin_list)
// 	{
// 		if (*begin_list && !cmp((*begin_list)->data, data_ref))
// 		{
// 			to_free = *begin_list;
// 			*begin_list = (*begin_list)->next;
// 			free(to_free);
// 		}
// 		else
// 			*begin_list = (*begin_list)->next;
// 	}
// }

void		test_ft_list_remove_if(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_REMOVE_IF");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
