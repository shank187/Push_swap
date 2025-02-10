/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:56:58 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/10 17:28:13 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av[])
{
	char **arr ;
	t_list *top_a;
	// t_list *top_b;
	if(ac < 2)
		ft_clear(0, 0, 0);
	arr = to_arr(ac, av);
	top_a = stock_args(arr);
	print_content(top_a);
}
