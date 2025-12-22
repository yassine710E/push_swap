#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_words(char *s, char sep)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] == sep)
		i++;
	while (i < ft_strlen(s))
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == 0))
			counter++;
		i++;
	}
	return (counter);
}

char	*allocate_str(char *s, int start, int end)
{
	char	*str;
	int		i_str;

	str = malloc(end - start + 1);
	i_str = 0;
	if (!str)
		return (NULL);
	while (start <= end)
		str[i_str++] = s[start++];
	str[i_str] = 0;
	return (str);
}

char	**free_error(char **pptr, int index_from)
{
	while (index_from >= 0)
	{
		free(pptr[index_from]);
		index_from--;
	}
	free(pptr);
	return (NULL);
}

char	**ft_split(char *s, char sep)
{
	char	**r_value;
	int		start;
	int		re_index;
	char	*word;
	int		i_r_value;

	r_value = malloc(sizeof(char *) * (count_words(s, sep) + 1));
	if (!r_value)
		return (NULL);
	i_r_value = 0;
	start = 0;
	while (s[start] == sep)
		start++;
	re_index = -1;
	while (start <= ft_strlen(s))
	{
		if (re_index == -1 && s[start] != sep)
			re_index = start;
		else if (re_index != -1 && (s[start] == sep || start == ft_strlen(s)))
		{
			word = allocate_str(s, re_index, start - 1);
			if (!word)
				return (free_error(r_value, i_r_value - 1));
			r_value[i_r_value++] = word;
			re_index = -1;
		}
		start++;
	}
	r_value[i_r_value] = 0;
	return (r_value);
}
