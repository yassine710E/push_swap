#include "push_swap_bonus.h"
#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s_s1;
	size_t	s_s2;
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s_s1 = ft_strlen(s1);
	s_s2 = ft_strlen(s2);
	ptr = malloc(s_s1 + s_s2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		size_s;
	char	*ptr;

	i = 0;
	size_s = ft_strlen(s);
	ptr = malloc((size_s + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
