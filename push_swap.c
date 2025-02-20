I/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:56:58 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/11 13:35:56 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handle_3num(t_list **top_a)
{
	int i;
	t_list *ptr;

	ptr = *top_a;
	i = 0;
	while(ptr && ++i && ptr -> index != 3 )
		ptr = ptr -> next;
	if(i == 2)
	{	
		rra(top_a);
		if(is_sorted(*top_a) == 0)	
			sa(top_a);
	}
	else if(i == 3)
	{
		sa(top_a);
	}
	else if(i == 1)
	{
		ra(top_a);
		if(is_sorted((*top_a)) == 0)	
			sa(top_a);
	}
}

void update_poses(t_list *stack, int is_b)
{
	int i;
	int size;
	t_list *ptr;

	i = 0;
	ptr = stack;
	size = ft_lstsize(stack);
	while(ptr)
	{
		ptr -> pos = i++;
		if(!is_b)
			ptr -> target_pos = ptr -> index - 1;	
		ptr = ptr -> next;
	}

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

void push_2b(t_list **top_a, t_list **top_b, int size_a)
{
	int i;

	i = 0;
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
	while(i < size_a - 3)
	{
		pb(top_a, top_b);
		i++;
	}
	handle_3num(top_a);
}

ft_abs(int n)
{
	if(n < 0)
		n *=(-1);
	return(n);
}

void best_move(t_list **top_a, t_list **top_b)
{
	t_list *tmp;
	int min_cost;

	min_cost = INT_MAX;
	tmp = *top_b;
	while(tmp)
	{
		tmp = tmp -> next;
	}
}

void sort_all(t_list **top_a,t_list **top_b)
{
	push_2b(top_a, top_b, ft_lstsize(*top_a));
	while(ft_lstsize(top_b))
	{
		update_infos(*top_a, *top_a);
		
	}
	
}

int main(int ac, char *av[])
{
	char **arr ;
	t_list *top_a;
	// t_list *top_b;

	if(ac < 2)
		ft_clear(0, 0, 0, 1);
	arr = to_arr(ac, av);
	top_a = stock_args(arr);
	print_content(top_a);
	if(is_sorted(top_a))
		return(ft_clear(&top_a, 0, 0, 0),1);
	else if(ft_lstsize(top_a) == 2)
		return(ft_printf("sa\n"),ft_clear(&top_a, 0, 0, 0), 1);
	else if (ft_lstsize(top_a) == 3)
		handle_3num(&top_a);
	else if (ft_lstsize(top_a) > 3)
	{

	}
		
}
