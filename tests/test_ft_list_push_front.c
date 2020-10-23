/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 19:22:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

// static void	ft_list_push_front_c(t_list **lst, t_list *new_elem)
// {
// 	if (lst && new_elem)
// 	{
// 		new_elem->next = *lst;
// 		*lst = new_elem;
// 	}
// }

// static void	compare_list_elem(t_list *test_lst)
// {
// 	g_results->test_num++;
// 	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
// }

void		test_ft_list_push_front(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_PUSH_FRONT");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
