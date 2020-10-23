/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 18:59:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	read_file(
	char *buf, const char *pathname, size_t count, int *read_errno)
{
	int		fd;
	int		ret;

	bzero(buf, BUFFER_SIZE + 1);
	fd = open(pathname, O_RDONLY);
	if (!fd)
		exit(EXIT_FAILURE);
	ret = read(fd, buf, count);
	printf("read:\t\t\"%s\" | ret: %d\n", buf, ret);
	if (ret == -1)
		*read_errno = errno;
	close(fd);
	return (ret);
}

static int	ft_read_file(
	char *buf, const char *pathname, size_t count, int *ft_errno)
{
	int		fd;
	int		ret;

	bzero(buf, BUFFER_SIZE + 1);
	fd = open(pathname, O_RDONLY);
	if (!fd)
		exit(EXIT_FAILURE);
	ret = ft_read(fd, buf, count);
	printf("ft_read:\t\"%s\" | ret: %d\n", buf, ret);
	if (ret == -1)
		*ft_errno = errno;
	close(fd);
	return (ret);
}

static void	compare_read_ret(char *buf, const char *pathname, size_t count)
{
	int		read_ret;
	int		ft_ret;
	int		read_errno;
	int		ft_errno;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	read_errno = 0;
	ft_errno = 0;
	read_ret = read_file(buf, pathname, count, &read_errno);
	ft_ret = ft_read_file(buf, pathname, count, &ft_errno);
	check_return(read_ret == ft_ret);
	if (read_errno && ft_errno)
		check_errno_val("read", read_errno, ft_errno);
}

void		test_ft_read(void)
{
	char	buf[BUFFER_SIZE + 1];

	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_READ");
	compare_read_ret(buf, "lol", TEST_NEG);
	compare_read_ret(buf, TEST_FD_PATH, TEST_NEG);
	compare_read_ret(buf, TEST_FD_PATH, DEFAULT_VALUE);
	compare_read_ret(buf, TEST_FD_PATH, TEST_SIZE);
	PRINT_SEP();
}
