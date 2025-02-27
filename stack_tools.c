/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:34:01 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 14:45:31 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_difr(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a > 0)
	{
		ra(stack_a, 1);
		a--;
	}
	while (b > 0)
	{
		rb(stack_b, 1);
		b--;
	}
	while (a < 0)
	{
		rra(stack_a, 1);
		a++;
	}
	while (b < 0)
	{
		rrb(stack_b, 1);
		b++;
	}
}

void	push_target(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a && b && ((a > 0) == (b > 0)))
	{
		if (a > 0 && b > 0)
		{
			rr(stack_a, stack_b, 1);
			a--;
			b--;
		}
		if (a < 0 && b < 0)
		{
			rrr(stack_a, stack_b, 1);
			a++;
			b++;
		}
	}
	handle_difr(stack_a, stack_b, a, b);
	pa(stack_a, stack_b, 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= (-1);
	return (n);
}

int	get_index(t_list *top_a, int number)
{
	t_list	*ptr;
	int		min_rank;
	int		max_rank;

	max_rank = 0;
	min_rank = 0;
	ptr = top_a;
	while (ptr)
	{
		if (number > (ptr -> content))
			if ((ptr -> index > max_rank))
				max_rank = ptr -> index;
		if (number < (ptr -> content))
		{
			if (min_rank > ptr -> index)
				min_rank = (ptr -> index);
			(ptr -> index)++;
		}
		ptr = ptr -> next;
	}
	if (min_rank)
		return (min_rank);
	return (max_rank + 1);
}

void	rrr(t_list **top_a, t_list **top_b, int wrt)
{
	rra(top_a, 0);
	rrb(top_b, 0);
	if (wrt)
		ft_printf("rrr\n", 1);
}
