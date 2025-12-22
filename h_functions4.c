#include "push_swap.h"

void	display_error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
}

t_list	*find_node(t_list *list, int data)
{
	while (list)
	{
		if (list->val == data)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int	get_chunk(int size_list)
{
	int	chunk;

	chunk = 20;
	if (size_list > 100)
	{
		chunk = 40;
	}
	return (chunk);
}

t_list	*get_max_node(t_list *head)
{
	t_list	*r_node;
	int		max_index_sort;

	if (head)
	{
		max_index_sort = head->index_sorted;
		r_node = head;
		head = head->next;
		while (head)
		{
			if (max_index_sort < head->index_sorted)
			{
				r_node = head;
				max_index_sort = head->index_sorted;
			}
			head = head->next;
		}
		return (r_node);
	}
	else
		return (NULL);
}
