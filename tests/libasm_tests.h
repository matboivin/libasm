/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_tests.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/19 17:46:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TESTS_H
# define LIBASM_TESTS_H

# include <stdbool.h>
# include <stdint.h>
# include <sys/stat.h>
# include <fcntl.h>

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
	int			test_num;
}				t_result;

extern t_result	*g_results;

/*
** Output formatting
*/

# define COL_RESET "\033[0m"
# define COL_WHITE_B "\033[1m"
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
	printf(																\
		"%s*******************************************************************************%s\n\n", COL_BLUE, COL_RESET);	\
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

# define PRINT_TEST_INPUT(num, input)									\
{																		\
	printf("%sTest n. %d:%s", COL_BLUE, num, COL_RESET);				\
	if (input)															\
		printf(" input -> \"%s\"", input);								\
	printf("\n");														\
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
	printf(																\
		"%s-> An error happened. Checking errno value:%s\n",			\
		COL_YELLOW_B, COL_RESET);										\
	printf(																\
		"%s errno:\t%d \"%s\"\n",										\
		func_name, ori_errno, strerror(ori_errno));						\
	printf(																\
		"ft_%s errno:\t%d \"%s\"\n",									\
		func_name, ft_errno, strerror(ft_errno));						\
}

# define PRINT_TEST_RESULTS(passed, total)								\
{																		\
	printf("%d/%d passed tests\n", passed, total);						\
	if (passed == total)												\
		printf("%s-> All tests passed%s\n\n", COL_GREEN_B, COL_RESET);	\
	else																\
		printf(															\
			"%s-> %d tests failed%s\n\n",								\
			COL_RED_B, (total - passed), COL_RESET);					\
	PRINT_SEP();														\
}

t_result	*malloc_result(void);
void		free_result(t_result *to_free);
void		check_return(bool condition);
void		check_errno_val(char *func_name, int ori_errno, int ft_errno);

void		test_ft_read(void);
void		test_ft_write(void);
void		test_ft_strcmp(void);
void		test_ft_strcpy(void);
void		test_ft_strdup(void);
void		test_ft_strlen(void);

#endif
