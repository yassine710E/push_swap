#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	int				index_value;
	int				index_sorted;
	struct s_list	*next;
}					t_list;

int					ft_strlen(char *s);
int					count_words(char *s, char sep);
char				*allocate_str(char *s, int start, int end);
void				free_error(char **pptr, int index_from);
char				**ft_split(char *s, char sep);
int					check_if_degit_string(char *str);
int					check_if_degits_arr_string(int c, char **v);
void				display_error(void);
long				ft_atoi(char *str, int *flag);
int					is_degit(char s);
int					is_spaces(char s);
int					contains_just_spaces(char *str);
int					ft_ptrlenght(char **pptr);
#endif