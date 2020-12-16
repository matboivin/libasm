/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:40:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:29:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_duplicates(char *s)
{
	char	*strdup_ret;
	char	*ft_ret;

	g_results->test_num++;
	PRINT_TEST_NUMBER(g_results->test_num);
	print_test_input(s, NULL);
	strdup_ret = strdup(s);
	ft_ret = ft_strdup(s);
	printf("strdup:\t\t\"%s\"\n", strdup_ret);
	printf("ft_strdup:\t\"%s\"\n", ft_ret);
	check_return(strcmp(strdup_ret, ft_ret) == 0);
	ft_strdel(&strdup_ret);
	ft_strdel(&ft_ret);
}

void		test_ft_strdup(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRDUP");
	compare_duplicates(TEST_STR_EMPTY);
	compare_duplicates(TEST_STR_HELLO);
	compare_duplicates(TEST_STR_HELL);
	compare_duplicates(TEST_STR_LOWER_AL);
	compare_duplicates(TEST_STR_UPPER_AL);
	compare_duplicates(TEST_STR_UPPER_FOO);
	compare_duplicates(TEST_STR_LOWER_BAR);
	compare_duplicates(TEST_STR_LOREM);
	PRINT_SEP();
}
