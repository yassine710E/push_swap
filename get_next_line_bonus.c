#include "push_swap_bonus.h"

void	set_stash_and_line(char **line, char **stash, char *pos_n)
{
	char	*tmp;

	*line = ft_substr(*stash, 0, pos_n - *stash + 1);
	tmp = *stash;
	*stash = ft_substr(tmp, pos_n - *stash + 1, ft_strchr(*stash, 0) - pos_n);
	free(tmp);
	tmp = NULL;
}

void	free_stash(char **stash, char **line, ssize_t r)
{
	if (!*stash || !**stash)
	{
		free(*stash);
		*stash = NULL;
	}
	if (*stash != NULL && *stash[0] != 0 && r == 0 && !*line)
	{
		*line = *stash;
		*stash = NULL;
	}
}

char	*get_line(int fd, char **stash, char *buffer, char *line)
{
	ssize_t	r;
	char	*pos_n;

	r = 1;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			break ;
		buffer[r] = 0;
		if (!*stash)
			*stash = ft_strdup("");
		*stash = ft_strjoin(*stash, buffer);
		pos_n = ft_strchr(*stash, '\n');
		if (pos_n)
		{
			set_stash_and_line(&line, &(*stash), pos_n);
			break ;
		}
	}
	free_stash(&(*stash), &line, r);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, &stash, buffer, line);
	free(buffer);
	buffer = NULL;
	return (line);
}
