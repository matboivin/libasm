/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:29:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_lenghts(char *s)
{
	size_t	strlen_ret;
	size_t	ft_ret;

	g_results->test_num++;
	PRINT_TEST_NUMBER(g_results->test_num);
	print_test_input(s, NULL);
	strlen_ret = strlen(s);
	ft_ret = ft_strlen(s);
	printf("strlen:\t\t%ld\n", strlen_ret);
	printf("ft_strlen:\t%ld\n", ft_ret);
	check_return(strlen_ret == ft_ret);
}

void		test_ft_strlen(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRLEN");
	compare_lenghts(TEST_STR_EMPTY);
	compare_lenghts(TEST_STR_HELLO);
	compare_lenghts(TEST_STR_HELL);
	compare_lenghts(TEST_STR_LOWER_AL);
	compare_lenghts(TEST_STR_UPPER_AL);
	compare_lenghts(TEST_STR_UPPER_FOO);
	compare_lenghts(TEST_STR_LOWER_BAR);
	compare_lenghts(TEST_STR_LOREM);
	PRINT_SEP();
}
