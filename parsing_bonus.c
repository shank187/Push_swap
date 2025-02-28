/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:54:31 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 20:24:17 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_spcnum_bonus(char *s)
{
	size_t	i;
	int		valid;

	i = 0;
	valid = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			valid = 1;
		else if ((s[i] < 48 || s[i] > 57) && s[i] != 32
			&& s[i] != 43 && s[i] != 45)
			return (0);
		i++;
	}
	return (valid);
}

char	**to_arr_bonus(int ac, char *av[])
{
	int		i;
	char	*s;

	if (!is_spcnum_bonus(av[1]))
		return (ft_clear_bonus(0, 0, 1), NULL);
	s = ft_strjoin_bonus(ft_strdup_bonus(""), av[1]);
	i = 2;
	while (i < ac)
	{
		if (!is_spcnum_bonus(av[i]))
			return (free(s), ft_clear_bonus(0, 0, 1), NULL);
		s = ft_strjoin_bonus(s, " ");
		if (!(s))
			return (ft_clear_bonus(0, 0, 1), NULL);
		(s) = ft_strjoin_bonus((s), av[i]);
		if (!(s))
			return (ft_clear_bonus(0, 0, 1), NULL);
		i++;
	}
	return (ft_split_bonus(s, ' '));
}

int	check_dubl_bonus(int n, t_list *top_a)
{
	if (!top_a)
		return (1);
	while (top_a)
	{
		if (n == top_a -> content)
			return (0);
		top_a = top_a -> next;
	}
	return (1);
}

t_list	*stock_args_bonus(char **arr)
{
	long	i;
	long	n;
	t_list	*node;
	t_list	*top_a;

	top_a = NULL;
	node = NULL;
	i = 0;
	while (arr && arr[i])
	{
		n = ft_atoi_bonus(arr[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (ft_clear_bonus(&top_a, arr, 1), NULL);
		else if (!check_dubl_bonus(n, top_a))
			return (ft_clear_bonus(&top_a, arr, 1), NULL);
		node = malloc(sizeof(t_list));
		if (!node)
			return (ft_clear_bonus(&top_a, arr, 1), NULL);
		node -> content = n;
		ft_lstadd_back_bonus(&top_a, node);
		i++;
	}
	ft_clear_bonus(0, arr, 0);
	return (top_a);
}

void	rrr_bonus(t_list **top_a, t_list **top_b)
{
	rra_bonus(top_a);
	rrb_bonus(top_b);
}
