/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:28:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static bool	cmp_are_equals(int strcmp_ret, int ft_ret)
{
	if ((strcmp_ret == 0) && (ft_ret == 0))
		return (true);
	if ((strcmp_ret > 0) && (ft_ret > 0))
		return (true);
	if ((strcmp_ret < 0) && (ft_ret < 0))
		return (true);
	return (false);
}

static void	compare_strings(char *s1, char *s2)
{
	int		strcmp_ret;
	int		ft_ret;

	strcmp_ret = 0;
	ft_ret = 0;
	g_results->test_num++;
	PRINT_TEST_NUMBER(g_results->test_num);
	print_test_input(s1, s2);
	strcmp_ret = strcmp(s1, s2);
	ft_ret = ft_strcmp(s1, s2);
	printf("strcmp:\t\t\"%d\"\n", strcmp_ret);
	printf("ft_strcmp:\t\"%d\"\n", ft_ret);
	check_return(cmp_are_equals(strcmp_ret, ft_ret));
}

void		print_warn_cmp(void)
{
	printf("%s-> Warning%s\n", COL_YELLOW_B, COL_RESET);
	printf(
		"strcmp() return different values for same string comparisons\n\
		\rThe difference is due to the implementation of strcmp and passed\
		\r flags.\nAs long as it conforms to the (<0, 0, >0), \
		\rit is correct.\n\n\
		\rstrcmp() returns an integer indicating the result of the comparison, \
		\ras follows:\n\
		\r  • 0, if the s1 and s2 are equal;\n\
		\r  • a negative value if s1 is less than s2;\n\
		\r  • a positive value if s1 is greater than s2\n\n");
}

void		test_ft_strcmp(void)
{
	char	*hello;
	char	*hell;

	hello = "Hello World!";
	hell = "Hell";
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRCMP");
	print_warn_cmp();
	compare_strings(TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_strings(hello, TEST_STR_EMPTY);
	compare_strings(TEST_STR_EMPTY, hello);
	compare_strings(hello, hello);
	compare_strings(hello, hell);
	compare_strings(hell, hello);
	compare_strings(TEST_STR_LOWER_AL, TEST_STR_LOWER_AL);
	compare_strings(TEST_STR_LOWER_AL, TEST_STR_UPPER_AL);
	compare_strings(TEST_STR_LOWER_BAR, TEST_STR_UPPER_FOO);
	compare_strings(TEST_STR_UPPER_FOO, TEST_STR_LOWER_BAR);
	compare_strings("célestin  le petit coquin", "célestin  le petit coquin");
	compare_strings("célestin  le petit coquin", "célestin  le peetit coquin");
	PRINT_SEP();
}
