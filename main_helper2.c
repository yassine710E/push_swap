#include "push_swap.h"

int	free_list_display_error(int *arr, t_list *list)
{
	if (arr)
		free(arr);
	if (list)
		free_all_list(list);
	display_error();
	return (0);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

int	parsing_function(t_list **list, int c, char **v, int **arr)
{
	int	flag;

	flag = 0;
	if (!set_list(c, v, &flag, &(*list)))
		return (0);
	if (!check_if_duplicate(*list))
		return (free_list_display_error(NULL, *list));
	*arr = allocate_arr(*list, ft_size_list(*list));
	if (!*arr)
		return (free_list_display_error(NULL, *list));
	sort_array(*arr, ft_size_list(*list), &flag);
	if (!flag)
		return (free_list_display_error(*arr, *list));
	return (1);
}

int	indexing(t_list *list, int *arr)
{
	int	j;

	j = -1;
	while (++j < ft_size_list(list))
	{
		if (find_node(list, arr[j]))
			find_node(list, arr[j])->index_sorted = j;
		else
			return (free_list_display_error(arr, list));
	}
	free(arr);
	return (1);
}

void	sorting(t_list **list, t_list **list2)
{
	if (ft_size_list(*list) == 2)
		sort_2(&(*list));
	else if (ft_size_list(*list) == 3)
		sort_3(&(*list));
	else if (ft_size_list(*list) <= 5)
	{
		sort_5_and_4(&(*list), &(*list2));
		free_all_list(*list2);
	}
	else
	{
		push_to_stack_b(&(*list), &(*list2));
		push_back_to_stack_a(&(*list), &(*list2));
	}
	free_all_list(*list);
}
