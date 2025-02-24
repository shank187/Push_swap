/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:38:01 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/24 15:58:18 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char *av[])
{
	// atexit(f);
	char **arr ;
	t_list *top_a;
	t_list *top_b;
	char *s;

	top_b = NULL;
	if(ac < 2)
		ft_clear(0, 0, 0, 1);
	arr = to_arr(ac, av);
	top_a = stock_args(arr);
	if(is_sorted(top_a))
		return(ft_clear(&top_a, 0, 0, 0),1);
	while(s)
	{
		s = get
	}	
}