/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:40:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 18:59:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_duplicates(const char *s)
{
	char	*strdup_ret;
	char	*ft_ret;
	int		check;
	int		strdup_errno;
	int		ft_errno;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, s, NULL);
	strdup_errno = 0;
	ft_errno = 0;
	strdup_ret = strdup(s);
	ft_ret = ft_strdup(s);
	printf("strdup:\t\t\"%s\"\n", strdup_ret);
	printf("ft_strdup:\t\"%s\"\n", ft_ret);
	check = strcmp(strdup_ret, ft_ret);
	check_return(check == 0);
	if (strdup_errno && ft_errno)
		check_errno_val("strdup", strdup_errno, ft_errno);
}

void		test_ft_strdup(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_STRDUP");
	compare_duplicates(TEST_STR_EMPTY);
	compare_duplicates(TEST_STR_00);
	compare_duplicates(TEST_STR_01);
	PRINT_SEP();
}
