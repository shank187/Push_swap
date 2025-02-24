/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:56:58 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/23 10:28:27 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max(t_list *ptr)
{
	int max;
	int val;

	max  = 0;
	val = 0;
	while(ptr)
	{
		if((ptr -> index) > max)
		{
			max = ptr -> index;
			val = ptr -> content;
		}
		ptr = ptr -> next;
   	}
	return(val);
}

void handle_3num(t_list **top_a)
{
	int i;
	int max_val;
	t_list *ptr;

	ptr = *top_a;
	i = 0;
	max_val = get_max(ptr);
	while(ptr && ++i && ptr -> content != max_val )
		ptr = ptr -> next;
	if(i == 2)
	{	
		rra(top_a, 1);
		if(is_sorted(*top_a) == 0)	
			sa(top_a, 1);
	}
	else if(i == 3)
	{
		sa(top_a, 1);
	}
	else if(i == 1)
	{
		ra(top_a, 1);
		if(is_sorted((*top_a)) == 0)	
			sa(top_a, 1);
	}
}

int is_sorted(t_list *top_a)
{
	int last;
	// print_content(top_a);
	last = INT_MIN;
	while(top_a)
	{
		if ((top_a -> content) < last)
			return(0);
		last = top_a -> content;
		top_a = top_a -> next;
	}
	// ft_printf("is sorted\n");
	return(1);
}


int main(int ac, char *av[])
{
	// atexit(f);
	char **arr ;
	t_list *top_a;
	t_list *top_b;

	top_b = NULL;
	if(ac < 2)
		ft_clear(0, 0, 0, 1);
	arr = to_arr(ac, av);
	top_a = stock_args(arr);
	// print_content(top_a, 0);
	if(is_sorted(top_a))
		return(ft_clear(&top_a, 0, 0, 0),1);
	else if(ft_lstsize(top_a) == 2)
		return(ft_printf("sa\n", 1),ft_clear(&top_a, 0, 0, 0), 1);
	else if (ft_lstsize(top_a) == 3)
		handle_3num(&top_a);
	else if (ft_lstsize(top_a) > 3)
		sort_all(&top_a, &top_b);
	ft_clear(&top_a, 0, 0, 0);
	// ft_printf("FINAL RESULT\n", 1);
	// print_content(top_a, 0);
}
