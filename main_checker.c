#include "push_swap.h"
#include "push_swap_bonus.h"

int	is_match(char *rule, char *input_rule)
{
	int	i;

	i = 0;
	while (rule[i] || input_rule[i])
	{
		if (rule[i] != input_rule[i])
			return (0);
		i++;
	}
	return (1);
}

void	apply_rules(char *input_rule, t_list **list, t_list **list2)
{
	if (is_match("sa\n", input_rule))
		swap_first_two(&(*list), "sa\n", 1);
	else if (is_match("ra\n", input_rule))
		rotate(&(*list), "ra\n", 1);
	else if (is_match("rra\n", input_rule))
		reverse_rotate(&(*list), "rra\n", 1);
	else if (is_match("pb\n", input_rule))
		push_front(&(*list), &(*list2), "pb\n", 1);
	else if (is_match("pa\n", input_rule))
		push_front(&(*list2), &(*list), "pa\n", 1);
	else if (is_match("rb\n", input_rule))
		rotate(&(*list2), "rb\n", 1);
	else if (is_match("rrb\n", input_rule))
		reverse_rotate(&(*list2), "rrb\n", 1);
}

int	check_if_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->val > list->next->val)
			return (0);
		list = list->next;
	}
	return (1);
}

void	display_result(int condition)
{
	if (condition)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int c, char **v)
{
	t_list	*list;
	int		*arr;
	char	*str;
	t_list	*list2;

	list = NULL;
	list2 = NULL;
	if (c >= 2 && check_if_degits_arr_string(c, v))
	{
		if (!parsing_function(&list, c, v, &arr))
			return (0);
		if (!indexing(list, arr))
			return (0);
		str = get_next_line(0);
		while (str)
		{
			apply_rules(str, &list, &list2);
			str = get_next_line(0);
		}
		display_result(check_if_sorted(list));
	}
	else if (!check_if_degits_arr_string(c, v))
		display_error();
	return (0);
}
