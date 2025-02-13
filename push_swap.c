/* ************************************************************************** */
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

int main(int ac, char *av[])
{
	char **arr ;
	t_list *top_a;
	// t_list *top_b;

	if(ac < 2)
		ft_clear(0, 0, 0, 1);
	arr = to_arr(ac, av);
	top_a = stock_args(arr);
	if(is_sorted(top_a))
		return(ft_clear(&top_a, 0, 0, 0),1);
	else if(ft_lstsize(top_a) == 2)
		return(ft_printf("sa\n"),ft_clear(&top_a, 0, 0, 0), 1);
		
	print_content(top_a);
}
