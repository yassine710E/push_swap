#include "push_swap.h"

int	main(int c, char **v)
{
	if (c >= 2 && check_if_degits_arr_string(c, v))
	{
        printf("kkkkkkkkkkkkkkkkk\n");
    }
    else if (!check_if_degits_arr_string(c,v))
    {
        write(1,"Error\n",5);
    }
    
	return (0);
}