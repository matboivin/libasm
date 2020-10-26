/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/26 12:07:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

/*
** Check parameters
*/

static void	print_usage(void)
{
	printf("Usage: ./libasm_tester [-h | --bonus]\n\noptional arguments:\n");
	printf("  -h       print this usage message\n");
	printf("  --bonus  run both mandatory and bonus tests\n");
	exit(EXIT_SUCCESS);
}

void		check_params(int argc, char **argv, bool *test_bonus)
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

/*
** Assert return values are the same
*/

void		check_return(bool condition)
{
	g_results->total += 1;
	if (condition)
	{
		g_results->passed += 1;
		PRINT_TEST_OK();
	}
	else
		PRINT_TEST_KO();
}

/*
** Assert errno values are the same
*/

void		check_errno_val(char *func_name, int ori_errno, int ft_errno)
{
	g_results->total += 1;
	PRINT_ERRNO_VAL(func_name, ori_errno, ft_errno);
	if (ori_errno == ft_errno)
	{
		g_results->passed += 1;
		PRINT_TEST_OK();
	}
	else
		PRINT_TEST_KO();
}
