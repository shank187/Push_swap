/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:21:33 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/26 15:29:49 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 65534
# endif

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_clear(t_list **lst, char **arr, int quit);
void	ft_printf(char *s, int fd);
int		ft_lstsize(t_list *lst);
t_list	*stock_args(char **arr);
t_list	*ft_lstlast(t_list *lst);
t_list	*get_beflast(t_list *lst);
int		check_dubl(int n, t_list *top_a);
int		get_index(t_list *top_a, int number);
char	**to_arr(int ac, char *av[]);
int		is_sorted(t_list *top_a);
void	sort_all(t_list **top_a, t_list **top_b);
void	update_infos(t_list *stack_a, t_list *stack_b);
int		ft_abs(int n);
void	best_smoves(t_list *top_b, int *a, int *b);
void	handle_3num(t_list **top_a);
void	push_target(t_list **stack_a, t_list **stack_b, int a, int b);
void	print_content(t_list *head, int more);
char	*get_ln(char **s, char **l, int fd);
char	*get_next_line(int fd);
size_t	ft_strlcat2(char *dst, const char *src, size_t dstsize);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char *s2, int is_s2_leak);
size_t	ft_strlen2(const char *s);
int		manage_prevs(char **s, char **l);
char	*xd(char **s, char **l, int j, int i);
void	rrb(t_list **top_b, int wrt);
void	rra(t_list **top_a, int wrt);
void	rrr(t_list **top_a, t_list **top_b, int wrt);
void	ra(t_list **top_a, int wrt);
void	rb(t_list **top_b, int wrt);
void	rr(t_list **top_a, t_list **top_b, int wrt);
void	sa(t_list **top_a, int wrt);
void	sb(t_list **top_b, int wrt);
void	ss(t_list **top_a, t_list **top_b, int wrt);
void	pb(t_list **top_a, t_list **top_b, int wrt);
void	pa(t_list **top_a, t_list **top_b, int wrt);
// void	print_content(t_list *head, int more);
int		ex_rotates(char *s, t_list **stack_a, t_list **stack_b);
int		ex_pushes(char *s, t_list **stack_a, t_list **stack_b);
int		ex_swaps(char *s, t_list **stack_a, t_list **stack_b);
int		ex_rrab(char *s, t_list **stack_a, t_list **stack_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
