/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:33:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_copies(t_result *count, char *s1, const char *s2)
{
	char	*strcpy_ret;
	char	*ft_ret;
	char	*dst;
	char	*src;
	int		check;

	dst = strdup(s1);
	src = strdup(s2);
	if (!dst || !src)
		exit(EXIT_FAILURE);
	strcpy_ret = strcpy(dst, src);
	ft_ret = ft_strcpy(dst, src);
	printf("dst: \"%s\" | src: \"%s\"\n", s1, s2);
	printf("strcpy:\t\t\"%s\"\n", strcpy_ret);
	printf("ft_strcpy:\t\"%s\"\n\n", ft_ret);
	check = strcmp(strcpy_ret, ft_ret);
	check_return((check == 0), count);
}

void		test_ft_strcpy(t_result *count)
{
	PRINT_TEST_NAME("FT_STRCPY");
	compare_copies(count, TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_copies(count, TEST_STR_00, TEST_STR_EMPTY);
	compare_copies(count, TEST_STR_EMPTY, TEST_STR_00);
	compare_copies(count, TEST_STR_01, TEST_STR_00);
	compare_copies(count, TEST_STR_00, TEST_STR_01);
	PRINT_TEST_RESULTS(count->passed, count->total);
}
