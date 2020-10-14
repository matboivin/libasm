/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/14 18:20:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_lenghts(const char *s)
{
	int		strlen_ret;
	int		ft_ret;

	strlen_ret = strlen(s);
	ft_ret = ft_strlen(s);
	printf("input: \"%s\"\n", s);
	printf("strlen:\t\t%d\n", strlen_ret);
	printf("ft_strlen:\t%d\n\n", ft_ret);
	assert(strlen_ret == ft_ret);
}

void		test_ft_strlen(void)
{
	printf("FT_STRLEN\n\n");
	compare_lenghts(TEST_STR_EMPTY);
	compare_lenghts(TEST_STR_00);
	printf("-------------------------- OK --------------------------\n");
}
