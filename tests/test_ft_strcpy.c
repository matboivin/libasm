/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 21:02:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_copies(const char *s)
{
	char	*strcpy_ret = NULL;
	char	*ft_ret = NULL;
	char	*dst = NULL;
	char	*ft_dst = NULL;
	char	*src = NULL;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, s, NULL);
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
	compare_copies(TEST_STR_00);
	compare_copies(TEST_STR_00);
	compare_copies(TEST_STR_01);
	compare_copies(TEST_STR_02);
	compare_copies(TEST_STR_03);
	compare_copies(TEST_STR_04);
	compare_copies(TEST_STR_05);
	PRINT_SEP();
}
