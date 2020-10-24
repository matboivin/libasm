/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 13:56:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int	ft_list_size_c(t_list *lst)
{
	int		size;

	size = 0;
	if (lst)
	{
		while (lst)
		{
			size++;
			lst = lst->next;
		}
	}
	return (size);
}

static void	compare_list_sizes(t_list *test_lst)
{
	int		c_ret;
	int		asm_ret;

	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	PRINT_TEST_LIST(test_lst);
	c_ret = ft_list_size_c(test_lst);
	asm_ret = ft_list_size(test_lst);
	printf("C function:\tlist size is %d\n", c_ret);
	printf("ASM function:\tlist size is %d\n", asm_ret);
	check_return(c_ret == asm_ret);
}

void		test_ft_list_size(void)
{
	t_list	*dummy_list;

	dummy_list = NULL;
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_SIZE");
	compare_list_sizes(dummy_list);
	ft_list_push_back(&dummy_list, ft_list_new(TEST_STR_00));
	compare_list_sizes(dummy_list);
	ft_list_push_back(&dummy_list, ft_list_new(TEST_STR_00));
	compare_list_sizes(dummy_list);
	ft_list_push_back(&dummy_list, ft_list_new(TEST_STR_00));
	compare_list_sizes(dummy_list);
	ft_list_del(&dummy_list);
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
