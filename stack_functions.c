#include "push_swap.h"

t_list	*create_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->val = data;
	node->index_sorted = -1;
	node->next = NULL;
	return (node);
}

void	append_node(t_list **list, int num)
{
	t_list	*head;
	t_list	*new_node;

	new_node = create_node(num);
	if (!new_node)
		return ;
	if (*list)
	{
		head = *list;
		while (head->next)
			head = head->next;
		head->next = new_node;
	}
	else
		*list = new_node;
}

int	ft_size_list(t_list *list)
{
	int	counter;

	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

void	free_all_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	check_if_duplicate(t_list *head)
{
	t_list	*head2;

	if (head)
	{
		while (head->next)
		{
			head2 = head->next;
			while (head2)
			{
				if (head->val == head2->val)
					return (0);
				head2 = head2->next;
			}
			head = head->next;
		}
		return (1);
	}
	return (0);
}
