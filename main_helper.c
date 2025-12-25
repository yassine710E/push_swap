#include "push_swap.h"

int	free_all_and_return_0(t_list *head, char **pptr)
{
	free_all_list((head));
	free(pptr);
	display_error();
	return (0);
}

int	is_number_format_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	set_list(int c, char **v, int *flag, t_list **list)
{
	int		i;
	int		j;
	char	**pptr;
	int		num;

	i = 0;
	while (++i < c)
	{
		j = -1;
		pptr = ft_split(v[i], ' ');
		if (!pptr)
			return (0);
		while (pptr[++j])
		{
			if (!is_number_format_valid(pptr[j]))
				return (free_all_and_return_0(*list, pptr));
			num = (int)ft_atoi(pptr[j], flag);
			free(pptr[j]);
			append_node(&(*list), num);
			if (*flag)
				return (free_all_and_return_0(*list, pptr));
		}
		free(pptr);
	}
	return (1);
}

void	push_to_stack_b(t_list **list, t_list **list2)
{
	int	chunk;
	int	pushed;

	chunk = get_chunk(ft_size_list((*list)));
	pushed = 0;
	while (ft_size_list(*list) > 0)
	{
		if ((*list)->index_sorted <= pushed)
		{
			push_front(&(*list), &(*list2), "pb\n", 0);
			rotate(&(*list2), "rb\n", 0);
			pushed++;
		}
		else if ((*list)->index_sorted <= pushed + chunk)
		{
			push_front(&(*list), &(*list2), "pb\n", 0);
			pushed++;
		}
		else
			rotate(&(*list), "ra\n", 0);
	}
}

void	push_back_to_stack_a(t_list **list, t_list **list2)
{
	int		pos;
	t_list	*max_node;
	t_list	*tmp;

	while (ft_size_list(*list2) > 0)
	{
		max_node = get_max_node(*list2);
		pos = 0;
		tmp = *list2;
		while (tmp && tmp->val != max_node->val)
		{
			tmp = tmp->next;
			pos++;
		}
		while ((*list2)->val != max_node->val)
		{
			if (pos <= ft_size_list(*list2) / 2)
				rotate(&(*list2), "rb\n", 0);
			else
				reverse_rotate(&(*list2), "rrb\n", 0);
		}
		push_front(&(*list2), &(*list), "pa\n", 0);
	}
	free_all_list(*list2);
}
