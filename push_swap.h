#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				val;
	int				index_sorted;
	struct s_list	*next;
}					t_list;

int					ft_strlen(char *s);
int					count_words(char *s, char sep);
char				*allocate_str(char *s, int start, int end);
char				**free_error(char **pptr, int index_from);
char				**ft_split(char *s, char sep);
int					check_if_degit_string(char *str);
int					check_if_degits_arr_string(int c, char **v);
void				display_error(void);
long				ft_atoi(char *str, int *flag);
int					is_degit(char s);
int					is_spaces(char s);
int					contains_just_spaces(char *str);
t_list				*create_node(int data);
void				append_node(t_list **list, t_list *node);
int					ft_size_list(t_list *list);
void				free_all_list(t_list *head);
int					check_if_duplicate(t_list *head);
void				swap_first_two(t_list **top, char *s_stack_op);
void				push_front(t_list **list_1, t_list **list_2,
						char *p_stack_name);
void				rotate(t_list **list, char *r_stack_name);
void				reverse_rotate(t_list **list, char *rr_stack_name);
int					*allocate_arr(t_list *list, int size);
void				sort_array(int *arr, int sizeArr, int *flag);
t_list				*find_node(t_list *list, int data);
int					get_chunk(int size_list);
t_list				*get_max_node(t_list *head);
#endif