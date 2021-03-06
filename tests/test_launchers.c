/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_launchers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:31:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

/*
** Mandatory tests launcher
*/

void	launch_tests(void)
{
	g_results = malloc_result();
	PRINT_TITLE("LIBASM TESTER");
	test_ft_read();
	test_ft_write();
	test_ft_strlen();
	test_ft_strcmp();
	test_ft_strcpy();
	test_ft_strdup();
	PRINT_TEST_NAME("MANDATORY PART RESULTS");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}

/*
** Bonus tests launcher
*/

void	launch_bonus_tests(void)
{
	PRINT_TITLE("BONUS TESTS");
	test_ft_list_size();
	PRINT_TEST_NAME("MANDATORY + BONUS PART RESULTS");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
