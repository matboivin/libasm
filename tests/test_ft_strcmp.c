/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 21:04:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_strings(t_result *count, char *s1, const char *s2)
{
	int		strcmp_ret;
	int		ft_ret;

	strcmp_ret = strcmp(s1, s2);
	ft_ret = ft_strcmp(s1, s2);
	printf("s1: \"%s\" | s2: \"%s\"\n", s1, s2);
	printf("strcmp:\t\t\"%d\"\n", strcmp_ret);
	printf("ft_strcmp:\t\"%d\"\n", ft_ret);
	check_return((strcmp_ret == ft_ret), count);
}

void		test_ft_strcmp(t_result *count)
{
	PRINT_TEST_NAME("FT_STRCMP");
	compare_strings(count, TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_strings(count, TEST_STR_00, TEST_STR_00);
	compare_strings(count, TEST_STR_00, TEST_STR_02);
	compare_strings(count, TEST_STR_02, TEST_STR_02);
	PRINT_TEST_RESULTS(count->passed, count->total);
}
