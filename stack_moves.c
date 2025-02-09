/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:34 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/09 21:38:44 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_list *top_b)
{
	int tmp;
	t_list *ptr;

	if(!top_b)
		return;
	ptr = top_b -> next;
	if(!ptr)
		return;
	tmp = ptr -> content;
	ptr -> content = top_b -> content;
	top_b -> content = tmp;
}

void sa(t_list *top_a)
{
	int tmp;
	t_list *ptr;

	if(!top_a)
		return;
	ptr = top_a -> next;
	if(!ptr)
		return;
	tmp = ptr -> content;
	ptr -> content = top_a -> content;
	top_a -> content = tmp;
}

void ss(t_list *top_a, t_list *top_b)
{
	sa(top_a);
	sb(top_b);
}

void pa(t_list *top_a, t_list *top_b)
{
	t_list *tmp;

	if(!top_b)
		return;
	tmp = top_b;
	top_b = top_b -> next;
	tmp -> next = top_a;
	top_a = tmp;
}

void pb(t_list *top_a, t_list *top_b)
{
	t_list *tmp;

	if(!top_b)
		return;
	tmp = top_a;
	top_a = top_a -> next;
	tmp -> next = top_b;
	top_b = tmp;
}

void rb(t_list *top_b)
{
	int n;
	t_list *tmp;
	n = ft_lstsize(top_b);

	if (!top_b || n < 2)
		return;
	else if(n == 2)
		sb(top_b);
	else
	{
		tmp = top_b;
		top_b = tmp -> next;
		ft_lstadd_back(&top_b, tmp);
	}
}

void ra(t_list *top_a)
{
	int n;
	t_list *tmp;
	n = ft_lstsize(top_a);
	if (!top_a || n < 2)
		return;
	else if(n == 2)
		sa(top_a);
	else
	{
		tmp = top_a;
		top_a = tmp -> next;
		ft_lstadd_back(&top_a, tmp);
	}
}

void rr(t_list *top_a, t_list *top_b)
{
	ra(top_a);
	rb(top_b);
}

void rra(t_list *top_a)
{
	t_list *last_node;
	t_list *bef_last;
	int n;

	n = ft_lstsize(top_a);
	if (!top_a || n < 2)
		return;
	else if(n == 2)
		sa(top_a);
	last_node = ft_lstlast(top_a);
	bef_last =  get_beflast(top_a);
	bef_last -> next = NULL;
	last_node -> next = top_a;
	top_a = last_node;
}

void rrb(t_list *top_b)
{
	t_list *last_node;
	t_list *bef_last;
	int n;

	n = ft_lstsize(top_b);
	if (!top_b || n < 2)
		return;
	else if(n == 2)
		sb(top_b);
	last_node = ft_lstlast(top_b);
	bef_last = get_beflast(top_b);
	bef_last -> next = NULL;
	last_node -> next = top_b;
	top_b = last_node;
}

void rrr(t_list *top_a, t_list *top_b)
{
	rra(top_a);
	rrb(top_b);
}
