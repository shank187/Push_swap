/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statistique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:56:58 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/26 08:58:18 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"


void	calc_costs(t_list *stack_b, int a_size, int b_size)
{
	if ((stack_b -> pos) <= b_size / 2)
		stack_b -> cost_b = stack_b -> pos;
	else
		stack_b -> cost_b = (stack_b -> pos) - b_size;
	if((stack_b -> target_pos) <= a_size / 2)
		stack_b -> cost_a = stack_b -> target_pos;
	else
		stack_b -> cost_a = (stack_b -> target_pos) - a_size;
}

int	aim_target(t_list *stack_b, t_list *stack_a)
{
	int	min;
	int	target;
	int	sml;
	int	sml_pos;

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

void	update_infos(t_list *stack_a, t_list *stack_b)
{
	int i;
	t_list *tmp;

	tmp = stack_a;
	i = 0;
	while(tmp)
		tmp->pos = i++, tmp = tmp->next;
	i = 0;
	tmp = stack_b;
	while(tmp)
	{
		tmp -> pos = i++;
		tmp -> target_pos = aim_target(tmp, stack_a);
		calc_costs(tmp, ft_lstsize(stack_a), ft_lstsize(stack_b));
		tmp = tmp->next;
	}
}

int ft_max(int a, int b)
{
	if(a > b)
		return (a);
	return(b);
}

void best_smoves(t_list *top_b, int *a, int *b) 
{
	int min_cost;
	int ca;
	int cb;
	int combined;

	min_cost = INT_MAX;
	while (top_b)
	{
		ca = top_b->cost_a;
		cb = top_b->cost_b;
		if ((ca > 0 && cb > 0) || (ca < 0 && cb < 0)) 
			combined = ft_max(ft_abs(ca), ft_abs(cb));
		else
			combined = ft_abs(ca) + ft_abs(cb);
		if (combined < min_cost)
		{
			min_cost = combined;
			*a = ca;
			*b = cb;
		}
		top_b = top_b->next;
	}
}

