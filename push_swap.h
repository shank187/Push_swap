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
  char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_clear(t_list **lst, char **arr, char *s, int quit);
void		ft_printf(char *s, int fd);
int ft_lstsize(t_list *lst);
t_list *stock_args(char **arr);
t_list	*ft_lstlast(t_list *lst);
t_list *get_beflast(t_list *lst);
int	check_dubl(int n, t_list *top_a);
int get_index(t_list *top_a, int number);
char **to_arr(int ac, char *av[]);
int is_sorted(t_list *top_a);
void sort_all(t_list **top_a,t_list **top_b);
void update_infos(t_list *stack_a, t_list *stack_b);
int	ft_abs(int n);
void best_smoves(t_list *top_b, int *a, int *b);
void handle_3num(t_list **top_a);
int find_smallest_pos(t_list *ptr);

void	rrb(t_list **top_b, int wrt);
void	rra(t_list **top_a, int wrt);
void	rrr(t_list **top_a, t_list **top_b, int wrt);
void	ra(t_list **top_a, int wrt);
void	rb(t_list **top_b, int wrt);
void	rr(t_list **top_a, t_list **top_b, int wrt);
void	sa(t_list **top_a, int wrt);
void 	sb(t_list **top_b, int wrt);
void	pb(t_list **top_a, t_list **top_b, int wrt);
void	pa(t_list **top_a, t_list **top_b, int wrt);

// testing
void print_content(t_list *head, int more);

#endif
