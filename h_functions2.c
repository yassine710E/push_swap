#include "push_swap.h"

int	is_degit(char s)
{
	return (s >= '0' && s <= '9');
}

int	is_spaces(char s)
{
	return (s == 32 || (s >= 9 && s <= 13));
}

int	check_if_degit_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] == '+' || str[i] == '-') || is_degit(str[i])
				|| is_spaces(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	filter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (!is_degit(str[i + 1]))
			{
				printf("%c\n", str[i + 1]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_if_degits_arr_string(int c, char **v)
{
	int i = 1;
	while (i < c)
	{
		if (!check_if_degit_string(v[i]) || !filter(v[i]))
			return (0);
		i++;
	}
	return (1);
}