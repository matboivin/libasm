/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_remove_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:32:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 20:09:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	ft_list_remove_if_c(
	t_list **begin_list, void *data_ref, int (*cmp)())
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

static void	test_remove_if_00(void)
{
	char	*ref[2] = { "FOO", "FOO" };
	t_list	*test_lst;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	bzero(&test_lst, sizeof(test_lst));
	ft_list_push_back(&test_lst, TEST_STR_04);
	ft_list_push_back(&test_lst, TEST_STR_04);
	ft_list_push_back(&test_lst, TEST_STR_05);
	PRINT_TEST_LIST(test_lst);
	printf("Remove if data == \"%s\t\n\n", TEST_NODE_3);
	print_ref(ref, 2);
	printf("\nASM result:\n");
	ft_list_remove_if_c(&test_lst, TEST_STR_05, data_cmp);
	ft_list_print(test_lst);
	check_return(ft_list_cmp(test_lst, ref) == 0);
	ft_list_del(&test_lst);
}

static void	test_remove_if_01(void)
{
	char	*ref[3] = { TEST_NODE_1, TEST_NODE_2, TEST_NODE_4 };
	t_list	*test_lst;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	bzero(&test_lst, sizeof(test_lst));
	ft_list_push_back(&test_lst, TEST_NODE_1);
	ft_list_push_back(&test_lst, TEST_NODE_2);
	ft_list_push_back(&test_lst, TEST_NODE_3);
	ft_list_push_back(&test_lst, TEST_NODE_4);
	PRINT_TEST_LIST(test_lst);
	printf("Remove if data == \"%s\t\n\n", TEST_NODE_3);
	print_ref(ref, 3);
	printf("\nASM result:\n");
	ft_list_remove_if_c(&test_lst, TEST_NODE_3, data_cmp);
	ft_list_print(test_lst);
	check_return(ft_list_cmp(test_lst, ref) == 0);
	ft_list_del(&test_lst);
}

void		test_ft_list_remove_if(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_REMOVE_IF");
	test_remove_if_00();
	test_remove_if_01();
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
