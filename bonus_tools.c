/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:07 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 18:21:04 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ex_rotates(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "ra", 10))
		return (ra_bonus(stack_a), 1);
	else if (!ft_strncmp(s, "rb", 10))
		return (rb_bonus(stack_b), 1);
	else if (!ft_strncmp(s, "rr", 10))
		return (rr_bonus(stack_a, stack_b), 1);
	return (0);
}

int	ex_pushes(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "pa", 10))
		return (pa_bonus(stack_a, stack_b), 1);
	else if (!ft_strncmp(s, "pb", 10))
		return (pb_bonus(stack_a, stack_b), 1);
	return (0);
}

int	ex_swaps(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "sa", 10))
		return (sa_bonus(stack_a), 1);
	else if (!ft_strncmp(s, "sb", 10))
		return (sb_bonus(stack_b), 1);
	else if (!ft_strncmp(s, "ss", 10))
		return (ss_bonus(stack_a, stack_b), 1);
	return (0);
}

int	ex_rrab(char *s, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(s, "rra", 10))
		return (rra_bonus(stack_a), 1);
	else if (!ft_strncmp(s, "rrb", 10))
		return (rrb_bonus(stack_b), 1);
	else if (!ft_strncmp(s, "rrr", 10))
		return (rrr_bonus(stack_a, stack_b), 1);
	return (0);
}
