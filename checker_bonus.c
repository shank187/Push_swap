/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:38:01 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/24 20:45:36 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_move()
{
	if str
}

int main(int ac, char *av[])
{
	char *inst ;
	t_list *top_a;
	t_list *top_b;
	char *s;

	top_b = NULL;
	if(ac < 2)
		ft_clear(0, 0, 0, 1);
	top_a = stock_args(to_arr(ac, av));
	if(is_sorted(top_a))
		return(ft_clear(&top_a, 0, 0, 0),1);
	while(s = get_next_line(0))
	{
		if(is_valid_move(s))
			inst = ft_strjoin(inst, s);
		else
			return(ft_clear(&top_a, 0, inst, 1), 0);
		free(s);
	}
}
