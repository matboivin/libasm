/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:40:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:57:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_duplicates(t_result *count, const char *s)
{
	char	*strdup_ret;
	char	*ft_ret;
	int		check;
	int		strdup_errno;
	int		ft_errno;

	strdup_errno = 0;
	ft_errno = 0;
	strdup_ret = strdup(s);
	ft_ret = ft_strdup(s);
	printf("input: \"%s\"\n", s);
	printf("strdup:\t\t\"%s\"\n", strdup_ret);
	printf("ft_strdup:\t\"%s\"\n\n", ft_ret);
	check = strcmp(strdup_ret, ft_ret);
	check_return((check == 0), count);
	if (strdup_errno && ft_errno)
		check_errno_val("strdup", strdup_errno, ft_errno, count);
}

void		test_ft_strdup(t_result *count)
{
	PRINT_TEST_NAME("FT_STRDUP");
	compare_duplicates(count, TEST_STR_EMPTY);
	compare_duplicates(count, TEST_STR_00);
	compare_duplicates(count, TEST_STR_01);
	PRINT_TEST_RESULTS(count->passed, count->total);
}
