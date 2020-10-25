/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 16:08:54 by mboivin          ###   ########.fr       */
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
	t_list	*test_lst[2];

	bzero(&test_lst, sizeof(test_lst));
	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	printf("C function:\n");
	ft_list_push_front_c(&test_lst[0], "C: 1ST INPUT");
	ft_list_push_front_c(&test_lst[0], "C: 2ND INPUT");
	ft_list_push_front_c(&test_lst[0], "C: 3RD INPUT");
	ft_list_push_front_c(&test_lst[0], "C: 4TH INPUT");
	ft_list_print(test_lst[0]);
	printf("\nASM function:\n");
	ft_list_push_front_c(&test_lst[1], "ASM: 1ST INPUT");
	ft_list_push_front_c(&test_lst[1], "ASM: 2ND INPUT");
	ft_list_push_front_c(&test_lst[1], "ASM: 3RD INPUT");
	ft_list_push_front_c(&test_lst[1], "ASM: 4TH INPUT");
	ft_list_print(test_lst[1]);
	printf("\n");
	ft_list_del(&test_lst[0]);
	ft_list_del(&test_lst[1]);
	PRINT_TEST_TO_CHECK();
}

static void	test_push_front_01(void)
{
	t_list	*test_lst[2];

	bzero(&test_lst, sizeof(test_lst));
	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	printf("C function:\n");
	ft_list_push_front_c(&test_lst[0], "C: A");
	ft_list_push_front_c(&test_lst[0], "C: B");
	ft_list_print(test_lst[0]);
	printf("\nASM function:\n");
	ft_list_push_front_c(&test_lst[1], "ASM: C");
	ft_list_push_front_c(&test_lst[1], "ASM: D");
	ft_list_push_front_c(&test_lst[1], "ASM: E");
	ft_list_push_front_c(&test_lst[1], "ASM: F");
	ft_list_push_front_c(&test_lst[1], "ASM: G");
	ft_list_print(test_lst[1]);
	printf("\n");
	ft_list_del(&test_lst[0]);
	ft_list_del(&test_lst[1]);
	PRINT_TEST_TO_CHECK();
}

void		test_ft_list_push_front(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_PUSH_FRONT");
	test_push_front_00();
	test_push_front_01();
	PRINT_SEP();
}
