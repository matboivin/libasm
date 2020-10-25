/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 16:25:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

/*
** Result counter
*/

t_result		*malloc_result(void)
{
	t_result	*result;

	result = malloc(sizeof(t_result));
	if (!result)
		exit(EXIT_FAILURE);
	result->total = 0;
	result->passed = 0;
	result->test_num = 0;
	return (result);
}

void			free_result(t_result *to_free)
{
	free(to_free);
}
