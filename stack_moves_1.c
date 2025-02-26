/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:27:07 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/26 14:31:23 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **top_b, int wrt)
{
	t_list	*tmp;

	if (!(*top_b) || !((*top_b)-> next))
		return ;
	tmp = (*top_b)-> next;
	(*top_b)-> next = (*top_b)-> next -> next;
	tmp -> next = (*top_b);
	(*top_b) = tmp;
	if (wrt)
		ft_printf("sb\n", 1);
}

void	sa(t_list **top_a, int wrt)
{
	t_list	*tmp;

	if (!(*top_a) || !((*top_a)-> next))
		return ;
	tmp = (*top_a)-> next;
	(*top_a)-> next = (*top_a)-> next -> next;
	tmp -> next = (*top_a);
	(*top_a) = tmp;
	if (wrt)
		ft_printf("sa\n", 1);
}

void	ss(t_list **top_a, t_list **top_b, int wrt)
{
	sa(top_a, 0);
	sb(top_b, 0);
	if (wrt)
		ft_printf("ss\n", 1);
}

void	pa(t_list **top_a, t_list **top_b, int wrt)
{
	t_list	*tmp;

	if (!(*top_b))
		return ;
	tmp = (*top_b);
	(*top_b) = (*top_b)-> next;
	tmp -> next = (*top_a);
	(*top_a) = tmp;
	if (wrt)
		ft_printf("pa\n", 1);
}

void	pb(t_list **top_a, t_list **top_b, int wrt)
{
	t_list	*tmp;

	if (!(*top_a))
		return ;
	tmp = (*top_a);
	(*top_a) = (*top_a)-> next;
	tmp -> next = (*top_b);
	(*top_b) = tmp;
	if (wrt)
		ft_printf("pb\n", 1);
}
