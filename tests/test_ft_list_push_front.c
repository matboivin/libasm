/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_push_front.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/24 14:03:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_list_push_front_c(t_list **lst, t_list *new_elem)
{
	if (lst && new_elem)
	{
		new_elem->next = *lst;
		*lst = new_elem;
	}
}

static void	create_test_list(t_list **test_lst)
{
	ft_list_push_back(test_lst, ft_list_new(TEST_STR_00));
	ft_list_push_back(test_lst, ft_list_new(TEST_STR_00));
	ft_list_push_back(test_lst, ft_list_new(TEST_STR_00));
}

static void	push_front_c(t_list *test_lst, t_list *new_elem)
{
	printf("C function:\n");
	ft_list_push_front_c(&test_lst, new_elem);
	ft_list_print(test_lst);
	ft_list_remove_if_c(&test_lst, new_elem->data);
}

static void	push_front_asm(t_list *test_lst, t_list *new_elem)
{
	printf("ASM function:\n");
	ft_list_push_front_c(&test_lst, new_elem);
	ft_list_print(test_lst);
	ft_list_remove_if_c(&test_lst, new_elem->data);
}

static void	compare_list_elem(t_list *new_elem)
{
	t_list	*test_lst;

	test_lst = NULL;
	create_test_list(&test_lst);
	g_results->test_num++;
	PRINT_TEST_INPUT(g_results->test_num, NULL, NULL);
	PRINT_TEST_LIST(test_lst);
	PRINT_TEST_NEW_ELEM(new_elem);
	push_front_c(test_lst, new_elem);
	push_front_asm(test_lst, new_elem);
	ft_list_del(&test_lst);
}

void		test_ft_list_push_front(void)
{
	g_results->test_num = 0;
	PRINT_TEST_NAME("FT_LIST_PUSH_FRONT");
	compare_list_elem(ft_list_new(TEST_STR_01));
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
