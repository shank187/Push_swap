/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:45:09 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 20:33:33 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
	struct s_list	*next;
}	t_list;

void	rb_bonus(t_list **top_b);
void	ra_bonus(t_list **top_a);
void	rr_bonus(t_list **top_a, t_list **top_b);
void	rra_bonus(t_list **top_a);
void	rrb_bonus(t_list **top_b);
void	sb_bonus(t_list **top_b);
void	sa_bonus(t_list **top_a);
void	ss_bonus(t_list **top_a, t_list **top_b);
void	pa_bonus(t_list **top_a, t_list **top_b);
void	pb_bonus(t_list **top_a, t_list **top_b);
void	rrr_bonus(t_list **top_a, t_list **top_b);
t_list	*stock_args_bonus(char **arr);
char	**to_arr_bonus(int ac, char *av[]);
int		is_spcnum_bonus(char *s);
int		check_dubl_bonus(int n, t_list *top_a);
char	*ft_strdup_bonus(const char *s1);
void	ft_printf_bonus(char *s, int fd);
char	*ft_substr_bonus(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_bonus(const char *s);
char	*ft_strjoin_bonus(char *s1, char *s2);
long	ft_atoi_bonus(const char *str);
t_list	*get_beflast_bonus(t_list *lst);
int		ft_lstsize_bonus(t_list *lst);
void	ft_clear_bonus(t_list **lst, char **arr, int quit);
void	ft_lstadd_back_bonus(t_list **lst, t_list *new);
t_list	*ft_lstlast_bonus(t_list *lst);
char	**ft_split_bonus(char *s, char c);
int		ex_rotates(char *s, t_list **stack_a, t_list **stack_b);
int		ex_pushes(char *s, t_list **stack_a, t_list **stack_b);
int		ex_swaps(char *s, t_list **stack_a, t_list **stack_b);
int		ex_rrab(char *s, t_list **stack_a, t_list **stack_b);
char	*get_ln(char **s, char **l, int fd);
char	*get_next_line(int fd);
size_t	ft_strlcat2(char *dst, const char *src, size_t dstsize);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char *s2, int is_s2_leak);
size_t	ft_strlen2(const char *s);
int		is_sorted_bonus(t_list *top_a);
size_t	ft_strlcpy_bonus(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat_bonus(char *dst, const char *src, size_t dstsize);
char	*xd(char **s, char **l, int j, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
