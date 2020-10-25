/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:32:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 16:43:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

// static void	ft_list_sort_c(t_list **begin_list, int (*cmp)())
// {
// 	t_list	*cursor;
// 	t_list	*next_list;
// 	t_list	*next_data;

// 	if (!begin_list || !cmp)
// 		return ;
// 	if (*begin_list)
// 	{
// 		cursor = *begin_list;
// 		while (cursor)
// 		{
// 			next_list = cursor->next;
// 			while (next_list)
// 			{
// 				if (!cmp(cursor->data, next_list->data))
// 				{
// 					next_data = cursor->data;
// 					cursor->data = next_list->data;
// 					next_list->data = next_data;
// 				}
// 				next_list = next_list->next;
// 			}
// 			cursor = cursor->next;
// 		}
// 	}
// }

void		test_ft_list_sort(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_SORT");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
