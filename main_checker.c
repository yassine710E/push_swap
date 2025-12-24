#include "push_swap.h"
#include "push_swap_bonus.h"

void apply_rules(void)
{

    
}

int	main(int c, char **v)
{
	t_list	*list;
	t_list	*list2;
	int		*arr;

	list = NULL;
	 list2 = NULL;
	if (c >= 2 && check_if_degits_arr_string(c, v))
	{
		if (!parsing_function(&list, c, v, &arr))
			return (0);
		if (!indexing(list, arr))
			return (0);
		sorting(&list, &list2);
        apply_rules();
	}
	else if (!check_if_degits_arr_string(c, v))
		display_error();
	return (0);
}
