/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/16 17:10:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_copies(char *s1, const char *s2)
{
	char	*strcpy_ret;
	char	*ft_ret;
	char	*dst;
	char	*src;

	dst = strdup(s1);
	src = strdup(s2);
	if (!dst || !src)
		exit(EXIT_FAILURE);
	strcpy_ret = strcpy(dst, src);
	ft_ret = ft_strcpy(dst, src);
	printf("dst: \"%s\" | src: \"%s\"\n", s1, s2);
	printf("strcpy:\t\t\"%s\"\n", strcpy_ret);
	printf("ft_strcpy:\t\"%s\"\n\n", ft_ret);
}

void		test_ft_strcpy(void)
{
	printf("FT_STRCPY\n\n");
	compare_copies(TEST_STR_EMPTY, TEST_STR_EMPTY);
	compare_copies(TEST_STR_00, TEST_STR_EMPTY);
	compare_copies(TEST_STR_EMPTY, TEST_STR_00);
	compare_copies(TEST_STR_01, TEST_STR_00);
	compare_copies(TEST_STR_00, TEST_STR_01);
	printf("-------------------------- OK --------------------------\n");
}
