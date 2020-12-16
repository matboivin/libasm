/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:31:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

t_result	*g_results;

int			main(int argc, char **argv)
{
	bool	test_bonus;
	int		ret_val;

	test_bonus = false;
	ret_val = 0;
	check_params(argc, argv, &test_bonus);
	launch_tests();
	if (test_bonus)
		launch_bonus_tests();
	PRINT_TITLE("END OF TESTS");
	if (g_results->passed != g_results->total)
		ret_val = 1;
	free_result(g_results);
	return (ret_val);
}
