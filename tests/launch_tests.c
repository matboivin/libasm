/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 13:31:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	launch_tests(void)
{
	g_results = malloc_result();
	PRINT_START();
	test_ft_read();
	test_ft_write();
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_strdup();
	printf("MANDATORY PART RESULTS\n\n");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}

void	launch_bonus_tests(void)
{
	PRINT_BONUS();
	test_ft_list_size();
	test_ft_list_push_front();
	printf("MANDATORY + BONUS PART RESULTS\n\n");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
