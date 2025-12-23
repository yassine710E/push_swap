#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(sizeof(char));
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (s[start + (++i)] && i < len)
		ptr[i] = s[start + i];
	ptr[i] = '\0';
	return (ptr);
}
