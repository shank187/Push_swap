/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:34:01 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/21 15:41:42 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_2b(t_list **top_a, t_list **top_b, int size_a)
{
	int i;

	i = 1;
	while(i < size_a / 2)
	{
		if((*top_a) -> index < size_a / 2)
		{
			pb(top_a, top_b);
			i++;
		}
		else
			ra(top_a);
	} 
	while(i <= size_a - 3)
	{
		pb(top_a, top_b);
		i++;
	}
	handle_3num(top_a);
}

void sort_all(t_list **top_a,t_list **top_b)
{
	int isrb;
	int a, b;

	push_2b(top_a, top_b, ft_lstsize(*top_a));
	while(ft_lstsize(top_b))
	{
		update_infos(*top_a, *top_a);
		best_smoves(top_b, &a, &b);
		push_target(top_a, top_b, a, b);
	}
	while(!is_sorted(*top_a))
		ra(top_a);
}

void push_target(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if(a && b && abs(a)/ a == abs(b) / b)
	{
		while(a && b)
		{
			if(a < 0 && b < 0)
				rrr(stack_a, stack_b), a++, b++;
			else if(a > 0 && b > 0)
				rr(stack_a, stack_b), a--, b--;
		}
		while(a || b)
		{
			if(a)
			{
				if(a > 0)
					ra(stack_a), a--;
				else if(a < 0)
					rra(stack_a), a++;
			}
			else if(b)
			{
				if(b > 0)
					rb(stack_b), b--;
				else if(b < 0)
					rrb(stack_b), b++;
			}
		}
	}
	else
	{
		while(b)
		{
			if (b > 0)
				rb(stack_b), b--;
			if (b < 0)
				rrb(stack_b), b++;
		}
		while(a)
		{
			if (a > 0)
				ra(stack_a), a--;
			if (a < 0)
				rra(stack_a), a++;
		}
	}
	pb(stack_a, stack_b);
}
