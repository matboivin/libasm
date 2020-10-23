/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_list_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:15:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/23 19:08:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_list		*ft_list_new(void *p_data)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->data = p_data;
	result->next = NULL;
	return (result);
}

void		ft_list_del(t_list **node)
{
	t_list	*cursor;
	t_list	*next_list;

	if (!node)
		return ;
	if (*node)
	{
		cursor = *node;
		while (cursor)
		{
			next_list = cursor->next;
			free(cursor->data);
			free(cursor);
			cursor = next_list;
		}
		*node = NULL;
	}
}

void		ft_list_push_back(t_list **head, t_list *new_node)
{
	t_list	*cursor;

	if (!head || !new_node)
		return ;
	if (*head)
	{
		cursor = *head;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = new_node;
	}
	else
		*head = new_node;
}

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
	ft_list_push_back(&dummy_list, ft_list_new(TEST_STR_01));
	compare_list_sizes(dummy_list);
	ft_list_push_back(&dummy_list, ft_list_new(TEST_STR_00));
	compare_list_sizes(dummy_list);
	PRINT_TEST_RESULTS(g_results->passed, g_results->total);
}
