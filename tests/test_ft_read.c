/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/17 19:15:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	read_file(const char *pathname, size_t count)
{
	FILE	*stream;
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	stream = fopen(pathname, READ_MODE);
	fd = fileno(stream);
	if (!stream || fd == -1)
		exit(EXIT_FAILURE);
	ret = read(fd, buffer, count);
	printf("read:\t\t\"%s\" | ret: %d\n", buffer, ret);
	if (ret == -1)
		printf("errno: %d\n", errno);
	printf("\n");
	fclose(stream);
	return (ret);
}

static int	ft_read_file(const char *pathname, size_t count)
{
	FILE	*stream;
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	stream = fopen(pathname, READ_MODE);
	fd = fileno(stream);
	if (!stream || fd == -1)
		exit(EXIT_FAILURE);
	ret = ft_read(fd, buffer, count);
	printf("ft_read:\t\"%s\" | ret: %d\n", buffer, ret);
	if (ret == -1)
		printf("errno: %d\n", errno);
	printf("\n");
	fclose(stream);
	return (ret);
}

static void	compare_read_ret(const char *pathname, size_t count)
{
	int		read_ret;
	int		ft_ret;

	read_ret = read_file(pathname, count);
	ft_ret = ft_read_file(pathname, count);
	assert(read_ret == ft_ret);
}

void		test_ft_read(void)
{
	printf("FT_READ\n\n");
	compare_read_ret(TEST_FD_PATH, TEST_NEG);
	compare_read_ret(TEST_FD_PATH, DEFAULT_VALUE);
	compare_read_ret(TEST_FD_PATH, TEST_SIZE);
	printf("------------------------------ OK ------------------------------\n");
}
