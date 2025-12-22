#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst)
		{
			new->next = *lst;
			*lst = new;
		}
		else
		{
			*lst = new;
		}
	}
}

void	swap_first_two(t_list **top, char *s_stack_op)
{
	t_list	*tmp;

	if ((*top) && (*top)->next)
	{
		tmp = *top;
		*top = (*top)->next;
		tmp->next = (*top)->next;
		(*top)->next = tmp;
		write(1, s_stack_op, ft_strlen(s_stack_op));
	}
}

void	push_front(t_list **list_1, t_list **list_2, char *p_stack_name)
{
	t_list	*to_stack_a;
	t_list	*tmp1;

	if (*list_1)
	{
		to_stack_a = create_node((*list_1)->val);
		if (!to_stack_a)
			return ;
		tmp1 = *list_1;
		to_stack_a->index_sorted = tmp1->index_sorted;
		*list_1 = (*list_1)->next;
		free(tmp1);
		tmp1 = NULL;
		ft_lstadd_front(&(*list_2), to_stack_a);
		write(1, p_stack_name, ft_strlen(p_stack_name));
	}
}

void	rotate(t_list **list, char *r_stack_name)
{
	t_list	*tmp;
	t_list	*head;

	if ((*list) && (*list)->next)
	{
		tmp = (*list);
		(*list) = (*list)->next;
		head = *list;
		while (head->next)
			head = head->next;
		head->next = tmp;
		head->next->next = NULL;
		write(1, r_stack_name, ft_strlen(r_stack_name));
	}
}

void	reverse_rotate(t_list **list, char *rr_stack_name)
{
	t_list	*head;
	t_list	*tmp;

	if ((*list) && (*list)->next)
	{
		head = *list;
		while (head->next && head->next->next)
			head = head->next;
		tmp = head->next;
		head->next = NULL;
		tmp->next = (*list);
		(*list) = tmp;
		write(1, rr_stack_name, ft_strlen(rr_stack_name));
	}
}
