/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:34:01 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/23 09:55:51 by aelbour          ###   ########.fr       */
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
			pb(top_a, top_b, 1);
			i++;
		}
		else
			ra(top_a, 1);
	}
	// return;
	while(i <= size_a - 3)
	{
		pb(top_a, top_b, 1);
		i++;
	}
	// printf("the top a index %i\n", (*top_a )-> index);
	handle_3num(top_a);
	// printf("the top a index %i\n", (*top_a )-> index);

	
}

void push_target(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if(a && b && ft_abs(a)/ a == ft_abs(b) / b)
	{
		while(a && b)
		{
			if(a < 0 && b < 0)
				rrr(stack_a, stack_b, 1), a++, b++;
			else if(a > 0 && b > 0)
				rr(stack_a, stack_b, 1), a--, b--;
		}
		while(a || b)
		{
			if(a)
			{
				if(a > 0)
					ra(stack_a, 1), a--;
				else if(a < 0)
					rra(stack_a, 1), a++;
			}
			else if(b)
			{
				if(b > 0)
					rb(stack_b, 1), b--;
				else if(b < 0)
					rrb(stack_b, 1), b++;
			}
		}
	}
	else
	{
		while(b)
		{
			if (b > 0)
				rb(stack_b, 1), b--;
			if (b < 0)
				rrb(stack_b, 1), b++;
		}
		while(a)
		{
			if (a > 0)
				ra(stack_a, 1), a--;
			if (a < 0)
				rra(stack_a, 1), a++;
		}
	}
	pa(stack_a, stack_b, 1);
}


void sort_all(t_list **top_a, t_list **top_b)
{
	int a, b;

	push_2b(top_a, top_b, ft_lstsize(*top_a));
	a = 0;
	b = 0;
	while(ft_lstsize(*top_b))
	{
		update_infos(*top_a, *top_b);
		best_smoves(*top_b, &a, &b);
		push_target(top_a, top_b, a, b);
	}
	// ft_printf("stack A:\n", 1);
	// print_content(*top_a, 0);

	while(!is_sorted(*top_a))
		ra(top_a, 1);
}

int get_index(t_list *top_a, int number)
{
	t_list *ptr;
	int max_rank, min_rank;

	max_rank = 0;
	min_rank = 0;
	ptr = top_a;
	while(ptr) 
	{
		if(number > (ptr -> content))
			if ((ptr -> index > max_rank))
				max_rank = ptr -> index;
		if(number < (ptr -> content))
		{
			if(min_rank > ptr -> index)
				min_rank = (ptr -> index); 
			(ptr -> index)++;
		}
		ptr = ptr -> next;
	}
	if(min_rank)
		return(min_rank);
	return(max_rank + 1);
}

