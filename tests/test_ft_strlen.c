/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/19 17:24:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_lenghts(const char *s)
{
	int		strlen_ret;
	int		ft_ret;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL);
	strlen_ret = strlen(s);
	ft_ret = ft_strlen(s);
	printf("input: \"%s\"\n", s);
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
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
