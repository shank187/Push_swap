/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:13:57 by aelbour           #+#    #+#             */
/*   Updated: 2025/03/01 15:53:33 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_5num(t_list **top_a, t_list **top_b)
{
	int	a;
	int	b;

	pb(top_a, top_b, 1);
	pb(top_a, top_b, 1);
	handle_3num(top_a);
	while (ft_lstsize(*top_b))
	{
		update_infos(*top_a, *top_b);
		best_smoves(*top_b, &a, &b);
		push_target(top_a, top_b, a, b);
	}
	while (!is_sorted(*top_a))
		ra(top_a, 1);
}

int	rr_or_rrr(t_list *stack)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	i = 0;
	while (stack)
	{
		if (stack -> content < min)
		{
			min = stack -> content;
			pos = i;
		}
		i++;
		stack = stack -> next;
	}
	if (pos <= i / 2)
		return (1);
	else
		return (0);
}
