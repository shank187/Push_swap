/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:00:34 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 17:16:46 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_spcnum(char *s)
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

char	**to_arr(int ac, char *av[])
{
	int		i;
	char	*s;

	if (!is_spcnum(av[1]))
		return (ft_clear(0, 0, 1), NULL);
	s = ft_strjoin(ft_strdup(""), av[1]);
	i = 2;
	while (i < ac)
	{
		if (!is_spcnum(av[i]))
			return (free(s), ft_clear(0, 0, 1), NULL);
		s = ft_strjoin(s, " ");
		if (!(s))
			return (ft_clear(0, 0, 1), NULL);
		(s) = ft_strjoin((s), av[i]);
		if (!(s))
			return (ft_clear(0, 0, 1), NULL);
		i++;
	}
	return (ft_split(s, ' '));
}

int	check_dubl(int n, t_list *top_a)
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

void	insert_data(t_list *node, t_list *top_a, int n)
{
	node -> content = n;
	if (!top_a)
		node -> index = 1;
	else
		node -> index = get_index(top_a, n);
}

t_list	*stock_args(char **arr)
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
		n = ft_atoi(arr[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (ft_clear(&top_a, arr, 1), NULL);
		else if (!check_dubl(n, top_a))
			return (ft_clear(&top_a, arr, 1), NULL);
		node = malloc(sizeof(t_list));
		if (!node)
			return (ft_clear(&top_a, arr, 1), NULL);
		insert_data(node, top_a, n);
		ft_lstadd_back(&top_a, node);
		i++;
	}
	ft_clear(0, arr, 0);
	return (top_a);
}
