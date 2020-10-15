/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/15 18:34:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_strings(char *s1, const char *s2)
{
	int		strcmp_ret;
	int		ft_ret;

	strcmp_ret = strcmp(s1, s2);
	ft_ret = ft_strcmp(s1, s2);
	printf("s1: \"%s\" | s2: \"%s\"\n", s1, s2);
	printf("strcmp:\t\t\"%d\"\n", strcmp_ret);
	printf("ft_strcmp:\t\"%d\"\n\n", ft_ret);
}

void		test_ft_strcmp(void)
{
	printf("FT_STRCMP\n\n");
	compare_strings(TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_strings(TEST_STR_00, TEST_STR_00);
	compare_strings(TEST_STR_00, TEST_STR_02);
	compare_strings(TEST_STR_02, TEST_STR_02);
	printf("-------------------------- OK --------------------------\n");
}
