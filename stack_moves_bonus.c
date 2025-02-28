/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:47:59 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 19:59:38 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rb_bonus(t_list **top_b)
{
	t_list	*tmp;

	if (!(*top_b) || !(*top_b)-> next)
		return ;
	else
	{
		tmp = (*top_b);
		(*top_b) = tmp -> next;
		ft_lstadd_back_bonus(top_b, tmp);
	}
}

void	ra_bonus(t_list **top_a)
{
	t_list	*tmp;

	if (!(*top_a) || !(*top_a)-> next)
		return ;
	else
	{
		tmp = (*top_a);
		(*top_a) = tmp -> next;
		ft_lstadd_back_bonus(top_a, tmp);
	}
}

void	rr_bonus(t_list **top_a, t_list **top_b)
{
	ra_bonus(top_a);
	rb_bonus(top_b);
}

void	rra_bonus(t_list **top_a)
{
	t_list	*last_node;
	t_list	*bef_last;

	if (!(*top_a) || !(*top_a)-> next)
		return ;
	else
	{
		last_node = ft_lstlast_bonus((*top_a));
		bef_last = get_beflast_bonus((*top_a));
		bef_last -> next = NULL;
		last_node -> next = *top_a;
		(*top_a) = last_node;
	}
}

void	rrb_bonus(t_list **top_b)
{
	t_list	*last_node;
	t_list	*bef_last;

	if (!(*top_b) || !(*top_b)-> next)
		return ;
	else
	{
		last_node = ft_lstlast_bonus((*top_b));
		bef_last = get_beflast_bonus((*top_b));
		bef_last -> next = NULL;
		last_node -> next = (*top_b);
		(*top_b) = last_node;
	}
}
