/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/26 16:24:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_strings(char *s1, const char *s2)
{
	int		strcmp_ret;
	int		ft_ret;

	strcmp_ret = 0;
	ft_ret = 0;
	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, s1, s2);
	strcmp_ret = strcmp(s1, s2);
	ft_ret = ft_strcmp(s1, s2);
	printf("strcmp:\t\t\"%d\"\n", strcmp_ret);
	printf("ft_strcmp:\t\"%d\"\n", ft_ret);
	check_return(strcmp_ret == ft_ret);
}

void		test_ft_strcmp(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRCMP");
	compare_strings(TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_strings(TEST_STR_00, TEST_STR_EMPTY);
	compare_strings(TEST_STR_EMPTY, TEST_STR_00);
	compare_strings(TEST_STR_00, TEST_STR_00);
	compare_strings(TEST_STR_00, TEST_STR_01);
	compare_strings(TEST_STR_01, TEST_STR_00);
	compare_strings(TEST_STR_02, TEST_STR_02);
	compare_strings(TEST_STR_02, TEST_STR_03);
	compare_strings(TEST_STR_04, TEST_STR_05);
	compare_strings(TEST_STR_05, TEST_STR_04);
	compare_strings(TEST_STR_05, TEST_STR_05);
	PRINT_SEP();
}
