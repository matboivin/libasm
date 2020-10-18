/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:37:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	check_return(bool condition, t_result *count)
{
	count->total += 1;
	if (condition)
	{
		count->passed += 1;
		PRINT_TEST_OK();
	}
	else
		PRINT_TEST_KO();
}
