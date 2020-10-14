/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/14 18:15:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TESTS_H
# define LIBASM_TESTS_H

# define DEFAULT_VALUE 0
# define READ_MODE "r"
# define BUFFER_SIZE 300
# define TEST_SIZE 42
# define TEST_STR_EMPTY ""
# define TEST_STR_00 "Hello World!"
# define TEST_FD_PATH "tests/libasm.h"

void	test_ft_write(void);
void	test_ft_read(void);
void	test_ft_strlen(void);

#endif
