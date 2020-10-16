/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/16 16:30:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_write_ret(int fd, const void *buf, size_t count)
{
	int		write_ret;
	int		ft_ret;

	printf("input: \"%s\n", buf);
	write_ret = write(fd, buf, count);
	printf("write:\t\t%d\n", write_ret);
	ft_ret = ft_write(fd, buf, count);
	printf("ft_write:\t%d\n\n", ft_ret);
	assert(write_ret == ft_ret);
}

void		test_ft_write(void)
{
	printf("FT_WRITE\n\n");
	//compare_write_ret(STDOUT_FILENO, NULL, TEST_SIZE);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, DEFAULT_VALUE);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, strlen(TEST_STR_00));
	printf("-------------------------- OK --------------------------\n");
}
