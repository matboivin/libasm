/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 14:52:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_lenghts(const char *s)
{
	int		strlen_ret;
	int		ft_ret;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, s, NULL);
	strlen_ret = strlen(s);
	ft_ret = ft_strlen(s);
	printf("strlen:\t\t%d\n", strlen_ret);
	printf("ft_strlen:\t%d\n", ft_ret);
	check_return(strlen_ret == ft_ret);
}

void		test_ft_strlen(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRLEN");
	compare_lenghts(TEST_STR_EMPTY);
	compare_lenghts(TEST_STR_00);
	compare_lenghts(TEST_STR_01);
	compare_lenghts(TEST_STR_02);
	compare_lenghts(TEST_STR_03);
	compare_lenghts(TEST_STR_04);
	compare_lenghts(TEST_STR_05);
	PRINT_SEP();
}
