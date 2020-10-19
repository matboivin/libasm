/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errno_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/19 17:42:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_errno_val(char *func_name, int ori_errno, int ft_errno)
{
	PRINT_ERRNO_VAL(func_name, ori_errno, ft_errno);
	if (ori_errno == ft_errno)
	{
		PRINT_TEST_OK();
	}
	else
		PRINT_TEST_KO();
}
