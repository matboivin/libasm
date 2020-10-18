/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:31:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_lenghts(t_result *count, const char *s)
{
	int		strlen_ret;
	int		ft_ret;

	strlen_ret = strlen(s);
	ft_ret = ft_strlen(s);
	printf("input: \"%s\"\n", s);
	printf("strlen:\t\t%d\n", strlen_ret);
	printf("ft_strlen:\t%d\n\n", ft_ret);
	check_return((strlen_ret == ft_ret), count);
}

void		test_ft_strlen(t_result *count)
{
	printf("FT_STRLEN\n\n");
	PRINT_TEST_NAME("FT_STRLEN");
	compare_lenghts(count, TEST_STR_EMPTY);
	compare_lenghts(count, TEST_STR_00);
	PRINT_TEST_RESULTS(count->passed, count->total);
}
