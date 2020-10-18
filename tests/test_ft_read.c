/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:53:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	read_file(const char *pathname, size_t n, int *read_errno)
{
	FILE	*stream;
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	stream = fopen(pathname, READ_MODE);
	fd = fileno(stream);
	if (!stream || fd == -1)
		exit(EXIT_FAILURE);
	ret = read(fd, buffer, n);
	printf("read:\t\t\"%s\" | ret: %d\n", buffer, ret);
	if (ret == -1)
		*read_errno = errno;
	fclose(stream);
	return (ret);
}

static int	ft_read_file(const char *pathname, size_t n, int *ft_errno)
{
	FILE	*stream;
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	stream = fopen(pathname, READ_MODE);
	fd = fileno(stream);
	if (!stream || fd == -1)
		exit(EXIT_FAILURE);
	ret = ft_read(fd, buffer, n);
	printf("ft_read:\t\"%s\" | ret: %d\n", buffer, ret);
	if (ret == -1)
		*ft_errno = errno;
	fclose(stream);
	return (ret);
}

static void	compare_read_ret(t_result *count, const char *pathname, size_t n)
{
	int		read_ret;
	int		ft_ret;
	int		read_errno;
	int		ft_errno;

	read_errno = 0;
	ft_errno = 0;
	read_ret = read_file(pathname, n, &read_errno);
	ft_ret = ft_read_file(pathname, n, &ft_errno);
	check_return((read_ret == ft_ret), count);
	if (read_errno && ft_errno)
		check_errno_val("read", read_errno, ft_errno, count);
}

void		test_ft_read(t_result *count)
{
	PRINT_TEST_NAME("FT_READ");
	compare_read_ret(count, TEST_FD_PATH, TEST_NEG);
	compare_read_ret(count, TEST_FD_PATH, DEFAULT_VALUE);
	compare_read_ret(count, TEST_FD_PATH, TEST_SIZE);
	PRINT_TEST_RESULTS(count->passed, count->total);
}
