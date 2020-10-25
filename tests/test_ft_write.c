/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/25 20:19:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

static void	compare_write_ret(int fd, const void *buf, size_t n)
{
	int		write_ret;
	int		write_errno;
	int		ft_ret;
	int		ft_errno;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, buf, NULL);
	write_errno = 0;
	ft_errno = 0;
	write_ret = write(fd, buf, n);
	if (write_ret == -1)
		write_errno = errno;
	printf("\nwrite:\t\t%d\n", write_ret);
	ft_ret = ft_write(fd, buf, n);
	if (ft_ret == -1)
		ft_errno = errno;
	printf("\nft_write:\t%d\n", ft_ret);
	check_return(write_ret == ft_ret);
	if (write_errno && ft_errno)
		check_errno_val("write", write_errno, ft_errno);
}

void		test_ft_write(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_WRITE");
	compare_write_ret(STDOUT_FILENO, NULL, TEST_SIZE);
	compare_write_ret(-1, NULL, TEST_SIZE);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, TEST_NEG);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, strlen(TEST_STR_00));
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, strlen(TEST_STR_05));
	PRINT_SEP();
}
