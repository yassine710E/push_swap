#include "push_swap.h"

int	main(int c, char **v)
{
	if (c >= 2 && check_if_degits_arr_string(c, v))
	{
		char **pptr = ft_split(v[1], ' ');
		int i = 1;
		int flag = 0;
		while (i < c)
		{
			int j = 0;
			char **pptr = ft_split(v[i], ' ');
			while (j < ft_ptrlenght(pptr))
			{
				long num = ft_atoi(pptr[j], &flag);
				if (flag)
				{
					display_error();
					return (0);
				}
				printf("%ld\n", num);
				j++;
			}

			i++;
		}
	}
	else if (!check_if_degits_arr_string(c, v))
		display_error();

	return (0);
}