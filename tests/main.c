/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 20:58:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_result	*g_results;

static void	print_usage(void)
{
	printf("Usage: ./libasm_tester [-h | --bonus]\n\noptional arguments:\n");
	printf("  -h       print this usage message\n");
	printf("  --bonus  run both mandatory and bonus tests\n");
	exit(EXIT_SUCCESS);
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
	PRINT_END();
	free_result(g_results);
	return (0);
}
