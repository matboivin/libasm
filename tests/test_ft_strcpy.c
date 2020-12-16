/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:29:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_copies(char *s)
{
	char	*strcpy_ret;
	char	*ft_ret;
	char	*dst;
	char	*ft_dst;
	char	*src;

	g_results->test_num++;
	PRINT_TEST_NUMBER(g_results->test_num);
	print_test_input(s, NULL);
	dst = ft_strnew(ft_strlen(s));
	ft_dst = ft_strnew(ft_strlen(s));
	src = strdup(s);
	if (!dst || !src)
		exit(EXIT_FAILURE);
	strcpy_ret = strcpy(dst, src);
	ft_ret = ft_strcpy(ft_dst, src);
	printf("strcpy:\t\t\"%s\"\n", strcpy_ret);
	printf("ft_strcpy:\t\"%s\"\n", ft_ret);
	check_return(strcmp(strcpy_ret, ft_ret) == 0);
	ft_strdel(&dst);
	ft_strdel(&ft_dst);
	ft_strdel(&src);
}

void		test_ft_strcpy(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRCPY");
	compare_copies(TEST_STR_EMPTY);
	compare_copies(TEST_STR_HELLO);
	compare_copies(TEST_STR_HELL);
	compare_copies(TEST_STR_LOWER_AL);
	compare_copies(TEST_STR_UPPER_AL);
	compare_copies(TEST_STR_UPPER_FOO);
	compare_copies(TEST_STR_LOWER_BAR);
	compare_copies(TEST_STR_LOREM);
	PRINT_SEP();
}
