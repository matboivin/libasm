/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:34:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int				main(void)
{
	t_result	count;

	PRINT_START();
	count.total = 0;
	count.passed = 0;
	test_ft_read(&count);
	test_ft_write(&count);
	test_ft_strlen(&count);
	test_ft_strcpy(&count);
	test_ft_strcmp(&count);
	test_ft_strdup(&count);
	PRINT_TEST_RESULTS(count.passed, count.total);
	PRINT_END();
	return (0);
}
