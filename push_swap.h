#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct	s_list *next;
} t_list;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
char	**ft_split(char *s, char c);
char **to_arr(int ac, char *av[]);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_clear(t_list **lst, char **arr, char *s, int quit);
int		ft_printf(const char *s, ...);
int ft_lstsize(t_list *lst);
t_list *stock_args(char **arr);
t_list	*ft_lstlast(t_list *lst);
t_list *get_beflast(t_list *lst);
int	check_dubl(int n, t_list *top_a);
// testing
void print_content(t_list *head);

#endif
