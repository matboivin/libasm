/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 00:12:45 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 13:32:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TEST_H
# define LIBASM_TEST_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libasm.h"

# define MIN_ARGC 1
# define MAX_ARGC 2
# define BONUS_OPT "--bonus"

/*
** Test values
*/

# define DEFAULT_VALUE 0
# define READ_MODE "r"
# define BUFFER_SIZE 300
# define TEST_FD_PATH "tests/libasm.h"
# define TEST_STR_EMPTY ""
# define TEST_STR_HELLO "Hello World!"
# define TEST_STR_HELL "Hell"
# define TEST_STR_LOWER_AL "a     bcd ef"
# define TEST_STR_UPPER_AL "A     BCD EF"
# define TEST_STR_UPPER_FOO "FOO"
# define TEST_STR_LOWER_BAR "bar"
# define TEST_STR_INTMAX "2147483647"
# define TEST_STR_INTMIN "-2147483648"
# define TEST_STR_LOREM "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."

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
		"%s_______________________________________________________________________________%s\n\n", COL_BLUE, COL_RESET);	\
}

# define PRINT_TITLE(title)												\
{																		\
	PRINT_SEP();														\
	printf("%40s%s%s\n\n", COL_BLUE_B, title, COL_RESET);				\
	PRINT_SEP();														\
}

# define PRINT_TEST_NAME(name)											\
{																		\
	printf("%s-> %s%s\n\n", COL_BLUE_B, name, COL_RESET);				\
}

# define PRINT_TEST_NUMBER(num)											\
{																		\
	printf("%sTest n. %d:%s\n", COL_BLUE, num, COL_RESET);				\
}

# define PRINT_TEST_LIST(test_lst)										\
{																		\
	printf("Input test list:\n");										\
	ft_list_print(test_lst);											\
	printf("\n");														\
}

# define PRINT_TEST_OK(void)											\
{																		\
	printf("%s-> [OK]%s\n\n", COL_GREEN_B, COL_RESET);					\
}

# define PRINT_TEST_KO(void)											\
{																		\
	printf("%s-> [KO]%s\n\n", COL_RED_B, COL_RESET);					\
}

# define PRINT_TEST_RESULTS(passed, total)								\
{																		\
	printf("%d/%d passed tests\n", passed, total);						\
	if (passed == total)												\
		printf("%s-> [OK] All tests passed%s\n\n",						\
		COL_GREEN_B, COL_RESET);										\
	else																\
		printf(															\
			"%s-> [KO] %d tests failed%s\n\n",							\
			COL_RED_B, (total - passed), COL_RESET);					\
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
** Test mandatory functions
*/

void			launch_tests(void);
void			test_ft_read(void);
void			test_ft_write(void);
void			test_ft_strcmp(void);
void			test_ft_strcpy(void);
void			test_ft_strdup(void);
void			test_ft_strlen(void);

/*
** Test bonus functions
*/

void			launch_bonus_tests(void);
void			test_ft_list_size(void);

/*
** Test utils
*/

void			check_params(int argc, char **argv, bool *test_bonus);
void			check_return(bool condition);
void			check_errno_val(char *func_name, int ori_errno, int ft_errno);
void			print_test_input(char *input1, char *input2);
t_result		*malloc_result(void);
void			free_result(t_result *to_free);
char			*ft_strnew(size_t size);
void			ft_strdel(char **to_free);
t_node			*ft_list_new(void *p_content);
void			ft_list_del(t_node **node);
void			ft_list_append(t_node **head, t_node *new_node);
void			ft_list_print(t_node *node);

#endif
