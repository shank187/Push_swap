/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:56:58 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/21 15:47:14 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

void update_infos(t_list *stack_a, t_list *stack_b)
{
	int i;
	t_list *tmp;

	tmp = stack_a;
	i = 0;
	while(tmp)
		tmp->pos = i++, tmp = tmp->next;
	tmp = stack_b;
	while(tmp)
	{
		tmp -> pos = i++;
		tmp -> target_pos = aim_target(tmp, stack_a);
		calc_costs(tmp, ft_lstsize(stack_a), ft_lstsize(stack_b));
		tmp = tmp->next;
	}
}
void best_smoves(t_list *top_b, int *a, int *b)
{
	t_list *tmp;
	int min_cost;
	int ca,cb;

	min_cost = INT_MAX;
	while(top_b)
	{
		ca = top_b -> cost_a;
		cb = top_b -> cost_b;
		if(ca && cb && ca / abs(ca) == cb / abs(cb))
		{
 			if(abs(abs(ca) - abs(cb)) < min_cost)
				min_cost = abs(abs(ca) - abs(cb)), *a = ca ,*b = cb;
		}
		else if(abs(ca) + abs(cb) < min_cost)
			min_cost = abs(ca) + abs(cb), *a = ca ,*b = cb;
		top_b = top_b -> next;
	}
}

void calc_costs(t_list *stack_b, int a_size, int b_size)
{
	if ((stack_b -> pos) <= b_size / 2)
		stack_b -> cost_b = stack_b -> pos;
	else
		stack_b -> cost_b = (stack_b -> pos) - b_size;
	if((stack_b -> target_pos) <= a_size)
		stack_b -> cost_a = stack_b -> target_pos;
	else
		stack_b -> cost_a = (stack_b -> target_pos) - a_size;
}

 int aim_target(t_list *stack_b, t_list *stack_a)
{
	int min, target, sml, sml_pos;

	min = INT_MAX;
	sml = INT_MAX;
	target = -1;
	while(stack_a)
	{
		if((stack_a -> index) > (stack_b -> index) && (stack_a -> index) < min)
		{
			target = stack_a -> pos;
			min = stack_a -> index;
		}
		if((stack_a -> index) < sml)
			{
				sml = stack_a -> index;
				sml_pos = stack_a -> pos;
			}
		stack_a = stack_a -> next;
	}
	if(target == -1)
		target = sml_pos;
	return(target);
}
