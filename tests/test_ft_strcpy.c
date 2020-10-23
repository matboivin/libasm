/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 19:04:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_copies(char *s1, const char *s2)
{
	char	*strcpy_ret;
	char	*ft_ret;
	char	*dst;
	char	*src;
	int		check;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, s1, s2);
	dst = strdup(s1);
	src = strdup(s2);
	if (!dst || !src)
		exit(EXIT_FAILURE);
	strcpy_ret = strcpy(dst, src);
	ft_ret = ft_strcpy(dst, src);
	printf("strcpy:\t\t\"%s\"\n", strcpy_ret);
	printf("ft_strcpy:\t\"%s\"\n", ft_ret);
	check = strcmp(strcpy_ret, ft_ret);
	check_return(check == 0);
}

void		test_ft_strcpy(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRCPY");
	compare_copies(TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_copies(TEST_STR_00, TEST_STR_EMPTY);
	compare_copies(TEST_STR_EMPTY, TEST_STR_00);
	compare_copies(TEST_STR_01, TEST_STR_00);
	compare_copies(TEST_STR_00, TEST_STR_01);
	PRINT_SEP();
}
