/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:47:06 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 20:32:26 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb_bonus(t_list **top_b)
{
	t_list	*tmp;

	if (!(*top_b) || !((*top_b)-> next))
		return ;
	tmp = (*top_b)-> next;
	(*top_b)-> next = (*top_b)-> next -> next;
	tmp -> next = (*top_b);
	(*top_b) = tmp;
}

void	sa_bonus(t_list **top_a)
{
	t_list	*tmp;

	if (!(*top_a) || !((*top_a)-> next))
		return ;
	tmp = (*top_a)-> next;
	(*top_a)-> next = (*top_a)-> next -> next;
	tmp -> next = (*top_a);
	(*top_a) = tmp;
}

void	ss_bonus(t_list **top_a, t_list **top_b)
{
	sa_bonus(top_a);
	sb_bonus(top_b);
}

void	pa_bonus(t_list **top_a, t_list **top_b)
{
	t_list	*tmp;

	if (!(*top_b))
		return ;
	tmp = (*top_b);
	(*top_b) = (*top_b)-> next;
	tmp -> next = (*top_a);
	(*top_a) = tmp;
}

void	pb_bonus(t_list **top_a, t_list **top_b)
{
	t_list	*tmp;

	if (!(*top_a))
		return ;
	tmp = (*top_a);
	(*top_a) = (*top_a)-> next;
	tmp -> next = (*top_b);
	(*top_b) = tmp;
}
