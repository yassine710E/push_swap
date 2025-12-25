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

size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char sep);
int					check_if_degit_string(char *str);
int					check_if_degits_arr_string(int c, char **v);
void				display_error(void);
long				ft_atoi(char *str, int *flag);
int					is_degit(char s);
int					is_spaces(char s);
int					contains_just_spaces(char *str);
t_list				*create_node(int data);
void				append_node(t_list **list, int num);
int					ft_size_list(t_list *list);
void				free_all_list(t_list *head);
int					check_if_duplicate(t_list *head);
void				swap_first_two(t_list **top, char *s_stack_op,
						int checker_flag);
void				push_front(t_list **list_1, t_list **list_2,
						char *p_stack_name, int checker_flag);
void				rotate(t_list **list, char *r_stack_name, int checker_flag);
void				reverse_rotate(t_list **list, char *rr_stack_name,
						int checker_flag);
int					*allocate_arr(t_list *list, int size);
void				sort_array(int *arr, int sizeArr, int *flag);
t_list				*find_node(t_list *list, int data);
int					get_chunk(int size_list);
t_list				*get_max_node(t_list *head);
void				sort_2(t_list **headz);
void				sort_3(t_list **head);
void				sort_5_and_4(t_list **list1, t_list **list2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					set_list(int c, char **v, int *flag, t_list **list);
void				push_to_stack_b(t_list **list, t_list **list2);
void				push_back_to_stack_a(t_list **list, t_list **list2);
int					parsing_function(t_list **list, int c, char **v, int **arr);
int					free_list_display_error(int *arr, t_list *list);
int					indexing(t_list *list, int *arr);
void				sorting(t_list **list, t_list **list2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
#endif