#include "push_swap.h"

long	ft_atoi(char *str, int *flag)
{
	long	result;
	int		i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result * sign < (long)INT_MIN || result * sign > (long)INT_MAX)
		*flag = 1;
	return (result * sign);
}

int	contains_just_spaces(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!is_spaces(str[i]))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

int	ft_ptrlenght(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
		i++;
	return (i);
}
