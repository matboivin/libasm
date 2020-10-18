/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errno_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:54:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_errno_val(
	char *func_name, int ori_errno, int ft_errno, t_result *count)
{
	PRINT_ERRNO_VAL(func_name, ori_errno, ft_errno);
	count->total += 1;
	if (ori_errno == ft_errno)
	{
		count->passed += 1;
		PRINT_TEST_OK();
	}
	else
		PRINT_TEST_KO();
}
