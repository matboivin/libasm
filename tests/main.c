/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 16:22:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

t_result	*g_results;

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
