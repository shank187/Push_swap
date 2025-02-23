/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:34 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/23 08:42:52 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_list **top_b, int wrt)
{
	t_list *tmp;

	if(!(*top_b) || !((*top_b) -> next))
		return;
	tmp = (*top_b) -> next;
	(*top_b) -> next = (*top_b) -> next -> next;
	tmp -> next = (*top_b);
	(*top_b) = tmp;
	if(wrt)
		ft_printf("sb\n", 1);
	// print_content((*top_b));
}

void	sa(t_list **top_a, int wrt)
{
	t_list *tmp;

	if(!(*top_a) || !((*top_a) -> next))
		return;
	tmp = (*top_a) -> next;
	(*top_a) -> next = (*top_a) -> next -> next;
	tmp -> next = (*top_a);
	(*top_a) = tmp;
	if(wrt)
		ft_printf("sa\n", 1);
	// print_content((*top_a));
}

void ss(t_list **top_a, t_list **top_b, int wrt)
{
	sa(top_a, 0);
	sb(top_b, 0);
	if(wrt)
		ft_printf("ss\n", 1);
}

void pa(t_list **top_a, t_list **top_b, int wrt)
{
	t_list *tmp;

	if(!(*top_b))
		return;
	tmp = (*top_b);
	(*top_b) = (*top_b) -> next;
	tmp -> next = (*top_a);
	(*top_a) = tmp;
	if(wrt)
		ft_printf("pa\n", 1);
}

void pb(t_list **top_a, t_list **top_b, int wrt)
{
	t_list *tmp;

	if(!(*top_a))
		return;
	tmp = (*top_a);
	(*top_a) = (*top_a) -> next;
	tmp -> next = (*top_b);
	(*top_b) = tmp;
	if(wrt)
		ft_printf("pb\n", 1);
}

void rb(t_list **top_b, int wrt)
{
	t_list *tmp;

	if (!(*top_b) || !(*top_b) -> next)
		return;
	else
	{
		tmp = (*top_b);
		(*top_b) = tmp -> next;
		ft_lstadd_back(top_b, tmp);
		if(wrt)
			ft_printf("rb\n", 1);
	}
}

void ra(t_list **top_a, int wrt)
{
	t_list *tmp;

	if (!(*top_a) || !(*top_a) -> next)
		return;
	else
	{
		tmp = (*top_a);
		(*top_a) = tmp -> next;
		ft_lstadd_back(top_a, tmp);
		if(wrt)
			ft_printf("ra\n", 1);
	}
}

void rr(t_list **top_a, t_list **top_b, int wrt)
{
	ra(top_a, 0);
	rb(top_b, 0);
	if(wrt)
		ft_printf("rr\n", 1);
}

void	rra(t_list **top_a, int wrt)
{
	t_list *last_node;
	t_list *bef_last;

	if (!(*top_a) || !(*top_a) -> next)
		return;
	else
	{
		last_node = ft_lstlast((*top_a));
		bef_last =  get_beflast((*top_a));
		bef_last -> next = NULL;
		last_node -> next = *top_a;
		(*top_a) = last_node;
		if(wrt)
			ft_printf("rra\n", 1);
	}
	// print_content((*top_a));
}

void rrb(t_list **top_b, int wrt)
{
	t_list *last_node;
	t_list *bef_last;

	if (!(*top_b) || !(*top_b) -> next)
		return;
	else
	{
		last_node = ft_lstlast((*top_b));
		bef_last = get_beflast((*top_b));
		bef_last -> next = NULL;
		last_node -> next = (*top_b);
		(*top_b) = last_node;
		if(wrt)
			ft_printf("rrb\n", 1);
	}
}

void rrr(t_list **top_a, t_list **top_b, int wrt)
{
	rra(top_a, 0);
	rrb(top_b, 0);
	if(wrt)
		ft_printf("rrr\n", 1);
}
