/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/29 16:47:55 by mboivin          ###   ########.fr       */
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
	check_return(cmp_are_equals(strcmp_ret, ft_ret));
}

void		print_warn_cmp(void)
{
	printf("%s-> Warning%s\n", COL_YELLOW_B, COL_RESET);
	printf(
		"strcmp() return different values for same string comparisons\n\
		\rThe difference is due to the implementation of strcmp and passed flags.\nAs long as it conforms to the (<0, 0, >0), it is correct.\n\n\
		\rstrcmp() returns an integer indicating the result of the comparison, as follows:\n\
		\r  • 0, if the s1 and s2 are equal;\n\
		\r  • a negative value if s1 is less than s2;\n\
		\r  • a positive value if s1 is greater than s2\n\n");
}

void		test_ft_strcmp(void)
{
	char	*empty = "";
	char	*hello = "Hello World!";
	char	*hell = "Hell";
	char	*lower_letters = TEST_STR_02;
	char	*upper_letters = TEST_STR_03;
	char	*foo = TEST_STR_04;
	char	*bar = TEST_STR_05;

	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRCMP");
	print_warn_cmp();
	compare_strings(empty, empty);
	compare_strings(hello, empty);
	compare_strings(empty, hello);
	compare_strings(hello, hello);
	compare_strings(hello, hell);
	compare_strings(hell, hello);
	compare_strings(lower_letters, lower_letters);
	compare_strings(lower_letters, upper_letters);
	compare_strings(bar, foo);
	compare_strings(foo, bar);
	compare_strings("célestin  le petit coquin", "célestin  le petit coquin");
	compare_strings("célestin  le petit coquin", "célestin  le peetit coquin");
	PRINT_SEP();
}
