/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/19 17:22:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	compare_write_ret(int fd, const void *buf, size_t n)
{
	int		write_ret;
	int		ft_ret;
	int		write_errno;
	int		ft_errno;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL);
	write_errno = 0;
	ft_errno = 0;
	printf("input: \"%s\"\n", buf);
	write_ret = write(fd, buf, n);
	printf("write:\t\t%d\n", write_ret);
	ft_ret = ft_write(fd, buf, n);
	printf("ft_write:\t%d\n", ft_ret);
	check_return(write_ret == ft_ret);
	if (write_errno && ft_errno)
		check_errno_val("write", write_errno, ft_errno);

}

void		test_ft_write(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_WRITE");
	compare_write_ret(STDOUT_FILENO, NULL, TEST_SIZE);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, TEST_NEG);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, DEFAULT_VALUE);
	compare_write_ret(STDOUT_FILENO, TEST_STR_00, strlen(TEST_STR_00));
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
