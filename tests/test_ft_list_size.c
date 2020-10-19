/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/19 19:16:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		test_ft_list_size(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_SIZE");
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
