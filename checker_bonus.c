/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:38:01 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/26 15:25:43 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			j;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	j = 0;
	while ((us1[j] && us2[j]) && us1[j] == us2[j] && j < n - 1 && n)
		j++;
	if (us1[j] < us2[j] && n)
		return (-1);
	if (us1[j] > us2[j] && n)
		return (1);
	return (0);
}

int	is_valid_move(char *s)
{
	if (!ft_strncmp(s, "sa\n", 10) || !ft_strncmp(s, "sb\n", 10)
		|| !ft_strncmp(s, "pb\n", 10) || !ft_strncmp(s, "pa\n", 10)
		|| !ft_strncmp(s, "ss\n", 10) || !ft_strncmp(s, "ra\n", 10)
		|| !ft_strncmp(s, "rb\n", 10) || !ft_strncmp(s, "rr\n", 10)
		|| !ft_strncmp(s, "rra\n", 10) || !ft_strncmp(s, "rrb\n", 10)
		|| !ft_strncmp(s, "rrr\n", 10))
		return (1);
	return (0);
}

int	execute_moves(char *s, t_list **stack_a, t_list **stack_b, int size_a)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(s, '\n');
	while (arr[i])
	{
		if (ex_pushes(arr[i], stack_a, stack_b))
			i++;
		else if (ex_rotates(arr[i], stack_a, stack_b))
			i++;
		else if (ex_swaps(arr[i], stack_a, stack_b))
			i++;
		else if (ex_rrab(arr[i], stack_a, stack_b))
			i++;
	}
	ft_clear(0, arr, 0);
	if (ft_lstsize(*stack_a) == size_a && is_sorted(*stack_a))
		return (1);
	return (0);
}

// void f()
// {
// 	system("leaks checker");
// }
int	main(int ac, char *av[])
{
	char	*inst ;
	t_list	*top_a;
	t_list	*top_b;
	char	*s;

	top_b = NULL;
	if (ac < 2)
		return (0);
	top_a = stock_args(to_arr(ac, av));
	if (!top_a)
		return (ft_printf("Error\n", 0), 0);
	s = get_next_line(0);
	while (s)
	{
		if (is_valid_move(s))
			inst = ft_strjoin(inst, s);
		else
			return (free(inst), ft_clear(&top_a, 0, 1), 0);
		free(s);
		s = get_next_line(0);
	}
	if (execute_moves(inst, &top_a, &top_b, ft_lstsize(top_a)))
		return (ft_printf("OK\n", 1), ft_clear(&top_a, 0, 0), 1);
	return (ft_printf("KO\n", 1), ft_clear(&top_a, 0, 0)
		, ft_clear(&top_b, 0, 0), 1);
}
