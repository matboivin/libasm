/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:40:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 14:46:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_duplicates(const char *s)
{
	char	*strdup_ret;
	char	*ft_ret;

	strdup_ret = strdup(s);
	ft_ret = ft_strdup(s);
	printf("input: \"%s\"\n", s);
	printf("strdup:\t\t\"%s\"\n", strdup_ret);
	printf("ft_strdup:\t\"%s\"\n\n", ft_ret);
}

void		test_ft_strdup(void)
{
	printf("FT_STRDUP\n\n");
	compare_duplicates(TEST_STR_EMPTY);
	compare_duplicates(TEST_STR_00);
	compare_duplicates(TEST_STR_01);
	printf("-------------------------- OK --------------------------\n");
}
