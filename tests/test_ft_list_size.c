/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:28:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_list_sizes(t_node *test_lst, int expected)
{
	int		ft_ret;

	g_results->test_num++;
	PRINT_TEST_NUMBER(g_results->test_num);
	PRINT_TEST_LIST(test_lst);
	ft_ret = ft_list_size(test_lst);
	printf("Expected result:\t%d\n", expected);
	printf("ft_list_size:\t%d\n", ft_ret);
	check_return(expected == ft_ret);
}

void		test_ft_list_size(void)
{
	t_node	*test_lst;

	test_lst = NULL;
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_SIZE");
	compare_list_sizes(test_lst, 0);
	ft_list_append(&test_lst, ft_list_new(TEST_STR_HELLO));
	compare_list_sizes(test_lst, 1);
	ft_list_append(&test_lst, ft_list_new(TEST_STR_UPPER_FOO));
	compare_list_sizes(test_lst, 2);
	ft_list_append(&test_lst, ft_list_new(TEST_STR_LOWER_BAR));
	compare_list_sizes(test_lst, 3);
	ft_list_del(&test_lst);
	PRINT_SEP();
}
