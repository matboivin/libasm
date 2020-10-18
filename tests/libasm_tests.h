/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/18 20:55:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TESTS_H
# define LIBASM_TESTS_H

# include <stdbool.h>
# include <stdint.h>

/*
** Test values
*/

# define DEFAULT_VALUE 0
# define READ_MODE "r"
# define BUFFER_SIZE 300
# define TEST_FD_PATH "tests/libasm.h"

# define TEST_SIZE 42
# define TEST_NEG -100

# define TEST_STR_EMPTY ""
# define TEST_STR_00 "Hello World!"
# define TEST_STR_01 "a     bcd ef"
# define TEST_STR_02 "Hell"

/*
** Result counter
*/

typedef	struct	s_result
{
	uint32_t	total;
	uint32_t	passed;
}				t_result;

/*
** Output formatting
*/

# define COL_RESET "\033[0m"
# define COL_RED "\033[0;31m"
# define COL_RED_B "\033[1;31m"
# define COL_GREEN "\033[0;32m"
# define COL_GREEN_B "\033[1;32m"
# define COL_YELLOW "\033[0;33m"
# define COL_YELLOW_B "\033[1;33m"
# define COL_BLUE "\033[0;34m"
# define COL_BLUE_B "\033[1;34m"

# define PRINT_SEP(void)												\
{																		\
	printf("%s*******************************************************************************%s\n\n", COL_BLUE, COL_RESET);	\
}

# define PRINT_START(void)												\
{																		\
	PRINT_SEP();														\
	printf("%40sLIBASM TESTS%s\n\n", COL_BLUE_B, COL_RESET);			\
	PRINT_SEP();														\
}

# define PRINT_END(void)												\
{																		\
	printf("%40sEND OF TESTS%s\n\n", COL_BLUE_B, COL_RESET);			\
	PRINT_SEP();														\
}

# define PRINT_TEST_NAME(name)											\
{																		\
	printf("%s-> %s%s\n\n", COL_BLUE_B, name, COL_RESET);				\
}

# define PRINT_TEST_OK(void)											\
{																		\
	printf("%s-> OK%s\n\n", COL_GREEN_B, COL_RESET);					\
}

# define PRINT_TEST_KO(void)											\
{																		\
	printf("%s-> KO%s\n\n", COL_RED_B, COL_RESET);						\
}

# define PRINT_ERRNO_VAL(func_name, ori_errno, ft_errno)				\
{																		\
	printf("%s-> Error happened. Checking errno value:%s\n", COL_YELLOW_B, COL_RESET);	\
	printf("%s errno:\t%d\n", func_name, ori_errno);						\
	printf("ft_%s errno:\t%d\n", func_name, ft_errno);					\
}

# define PRINT_TEST_RESULTS(passed, total)								\
{																		\
	printf("%d/%d passed tests\n", passed, total);						\
	if (passed == total)												\
		printf("%s-> All tests passed%s\n\n", COL_GREEN_B, COL_RESET);	\
	else																\
		printf("%s-> %d tests failed%s\n\n", COL_RED_B, (total - passed), COL_RESET);	\
	PRINT_SEP();														\
}

void	check_return(bool condition, t_result *count);
void	check_errno_val(
	char *func_name, int ori_errno, int ft_errno, t_result *count);

void	test_ft_strcmp(t_result *count);
void	test_ft_strcpy(t_result *count);
void	test_ft_strdup(t_result *count);
void	test_ft_strlen(t_result *count);
void	test_ft_write(t_result *count);
void	test_ft_read(t_result *count);

#endif
