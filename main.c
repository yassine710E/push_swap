#include "push_swap.h"

int	main(int c, char **v)
{
	if (c >= 2 && check_if_degits_arr_string(c, v))
	{
		int i = 1;
		int flag = 0;
		t_list *list = NULL;
		t_list *list2 = NULL;
		while (i < c)
		{
			int j = 0;
			char **pptr = ft_split(v[i], ' ');

			while (pptr[j])
			{
				int num = (int)ft_atoi(pptr[j], &flag);
				free(pptr[j]);
				t_list *node = create_node(num);
				append_node(&list, node);

				if (flag)
				{
					free_all_list(list);
					free(pptr);
					display_error();

					return (0);
				}
				j++;
			}
			free(pptr);
			pptr = NULL;
			i++;
		}
		if (!check_if_duplicate(list))
		{
			free_all_list(list);
			display_error();
			return (0);
		}
		//indexing the list from the smallest to bigger
		int *arr = allocate_arr(list, ft_size_list(list));
		sort_array(arr, ft_size_list(list), &flag);
		if (!flag)
			return (0);
		t_list *tmp;
		int j = 0;
		while (j < ft_size_list(list))
		{
			tmp = find_node(list, arr[j]);
			if (tmp)
				tmp->index_sorted = j;
			j++;
		}
		free(arr);
		int chunk = get_chunk(ft_size_list(list));
		int pushed = 0;
		//pushed = 4

		while (ft_size_list(list) > 0)
		{
			if (list->index_sorted <= pushed)
			{
				push_front(&list, &list2);
				write(1, "pb\n", 3);
				rotate(&list2);
				write(1, "rb\n", 3);
				pushed++;
			}

			else if (list->index_sorted <= pushed + chunk)
			{
				push_front(&list, &list2);
				write(1, "pb\n", 3);
				pushed++;
			}
			else
			{
				rotate(&list);
				write(1, "ra\n", 3);
			}
		}
		t_list *max_node;
		while (ft_size_list(list2) > 0)
		{
			max_node = get_max_node(list2);

			int pos = 0;
			t_list *tmp = list2;
			while (tmp && tmp->val != max_node->val)
			{
				tmp = tmp->next;
				pos++;
			}

			int size = ft_size_list(list2);

			while (list2->val != max_node->val)
			{
				if (pos <= size / 2)
				{
					rotate(&list2);
					write(1, "rb\n", 3);
				}
				else
				{
					reverse_rotate(&list2);
					write(1, "rrb\n", 4);
				}
			}

			push_front(&list2, &list);
			write(1, "pa\n", 3);
		}
		ft_print_list(list);
		free_all_list(list2);
		free_all_list(list);
	}
	else if (!check_if_degits_arr_string(c, v))
		display_error();

	return (0);
}