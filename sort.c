#include "push_swap.h"

void	sort_2(t_list **head)
{
	if (*head && (*head)->next && (*head)->val > (*head)->next->val)
	{
		swap_first_two(&(*head), "sa\n");
	}
}

void	sort_3(t_list **head)
{
	t_list	*max;

	max = get_max_node(*head);
	if ((*head) && max && (*head)->val == max->val)
		rotate(&(*head), "ra\n");
	else if ((*head) && (*head)->next && max && (*head)->next->val == max->val)
		reverse_rotate(&(*head), "rra\n");
	sort_2(&(*head));
}

t_list	*get_min(t_list *head)
{
	t_list	*min_node;

	min_node = head;
	head = head->next;
	while (head)
	{
		if (min_node->val > head->val)
			min_node = head;
		head = head->next;
	}
	return (min_node);
}

void	get_min_to_top_and_push_it(t_list **list1, t_list **list2)
{
	t_list	*head;
	t_list	*min;
	int		pos;

	head = *list1;
	min = get_min(head);
	pos = 0;
	while (head && min && (head)->val != min->val)
	{
		pos++;
		head = head->next;
	}
	while ((*list1)->val != min->val)
	{
		if (pos <= ft_size_list((*list1)) / 2)
			rotate(&(*list1), "ra\n");
		else
			reverse_rotate(&(*list1), "rra\n");
	}
	push_front(&(*list1), &(*list2), "pb\n");
}

void	sort_5_and_4(t_list **list1, t_list **list2)
{
	if (ft_size_list(*list1) == 5)
		get_min_to_top_and_push_it(&(*list1), &(*list2));
	if (ft_size_list(*list1) == 4)
		get_min_to_top_and_push_it(&(*list1), &(*list2));
	sort_3(&(*list1));
	while (ft_size_list(*list2) > 0)
		push_front(&(*list2), &(*list1), "pa\n");
}
