/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/19 19:31:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_result	*g_results;

static void	print_usage(void)
{
	printf("Usage: ./test_libasm [--bonus]\n\n");
	exit(EXIT_FAILURE);
}

static void	check_params(int argc, char **argv, bool *test_bonus)
{
	if ((argc < MIN_ARGC) || (argc > MAX_ARGC))
		print_usage();
	if (argc == MAX_ARGC)
	{
		if (strcmp(argv[1], BONUS_OPT))
			print_usage();
		*test_bonus = true;
	}
}

int			main(int argc, char **argv)
{
	bool	test_bonus;

	test_bonus = false;
	check_params(argc, argv, &test_bonus);
	launch_tests();
	if (test_bonus)
		launch_bonus_tests();
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
	PRINT_END();
	free_result(g_results);
	return (0);
}
