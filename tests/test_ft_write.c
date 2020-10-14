/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/14 16:59:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void		test_ft_write(void)
{
	printf("FT_WRITE:\n");
	assert(write(STDOUT_FILENO, TEST_STR_00, strlen(TEST_STR_00)) == ft_write(STDOUT_FILENO, TEST_STR_00, strlen(TEST_STR_00)));
}
