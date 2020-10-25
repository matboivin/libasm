/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 20:21:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	ft_list_push_front_c(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_list_new(data);
	if (begin_list && new_elem)
	{
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
}

static void	test_push_front_00(void)
{
	char	*ref[4] = { TEST_NODE_4, TEST_NODE_3, TEST_NODE_2, TEST_NODE_1 };
	t_list	*test_lst;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	print_ref(ref, 4);
	printf("\nASM result:\n");
	bzero(&test_lst, sizeof(test_lst));
	ft_list_push_front_c(&test_lst, TEST_NODE_1);
	ft_list_push_front_c(&test_lst, TEST_NODE_2);
	ft_list_push_front_c(&test_lst, TEST_NODE_3);
	ft_list_push_front_c(&test_lst, TEST_NODE_4);
	ft_list_print(test_lst);
	check_return(ft_list_cmp(test_lst, ref) == 0);
	ft_list_del(&test_lst);
}

static void	test_push_front_01(void)
{
	char	*ref[5] = { "E", "D", "C", "B", "A" };
	t_list	*test_lst;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	print_ref(ref, 5);
	printf("\nASM result:\n");
	bzero(&test_lst, sizeof(test_lst));
	ft_list_push_front_c(&test_lst, "A");
	ft_list_push_front_c(&test_lst, "B");
	ft_list_push_front_c(&test_lst, "C");
	ft_list_push_front_c(&test_lst, "D");
	ft_list_push_front_c(&test_lst, "E");
	ft_list_print(test_lst);
	check_return(ft_list_cmp(test_lst, ref) == 0);
	ft_list_del(&test_lst);
}

void		test_ft_list_push_front(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_PUSH_FRONT");
	test_push_front_00();
	test_push_front_01();
	PRINT_SEP();
}
