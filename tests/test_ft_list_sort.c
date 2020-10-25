/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:32:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 20:00:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	ft_list_sort_c(t_list **begin_list, int (*cmp)())
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

static void	test_sort_00(void)
{
	char	*ref[3] = { "FOO", "FOO", "bar" };
	t_list	*test_lst;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	bzero(&test_lst, sizeof(test_lst));
	ft_list_push_back(&test_lst, TEST_STR_04);
	ft_list_push_back(&test_lst, TEST_STR_05);
	ft_list_push_back(&test_lst, TEST_STR_04);
	PRINT_TEST_LIST(test_lst);
	print_ref(ref, 3);
	printf("\nASM result:\n");
	ft_list_sort_c(&test_lst, data_cmp);
	ft_list_print(test_lst);
	check_return(ft_list_cmp(test_lst, ref) == 0);
	ft_list_del(&test_lst);
}

static void	test_sort_01(void)
{
	char	*ref[4] = { "FOO", "FOO", "FOO", "A     BCD EF" };
	t_list	*test_lst;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	bzero(&test_lst, sizeof(test_lst));
	ft_list_push_back(&test_lst, TEST_STR_03);
	ft_list_push_back(&test_lst, TEST_STR_04);
	ft_list_push_back(&test_lst, TEST_STR_04);
	ft_list_push_back(&test_lst, TEST_STR_04);
	PRINT_TEST_LIST(test_lst);
	print_ref(ref, 4);
	printf("\nASM result:\n");
	ft_list_sort_c(&test_lst, data_cmp);
	ft_list_print(test_lst);
	check_return(ft_list_cmp(test_lst, ref) == 0);
	ft_list_del(&test_lst);
}

void		test_ft_list_sort(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_SORT");
	test_sort_00();
	test_sort_01();
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
