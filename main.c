/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychabane <ychabane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:29:54 by ychabane          #+#    #+#             */
/*   Updated: 2025/12/25 16:05:15 by ychabane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
	else if (!check_if_degits_arr_string(c, v))
		display_error();
	return (0);
}
