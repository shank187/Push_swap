I'm/* ************************************************************************** */
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

void handle_3num(t_list **top_a)
{
	int i;
	t_list *ptr;

	ptr = *top_a;
	i = 0;
	while(ptr && ++i && ptr -> index != 3 )
		ptr = ptr -> next;
	if(i == 2)
	{	
		if(is_sorted(*top_a = rra(*top_a)) == 0)	
			sa(*top_a);
	}
	else if(i == 3)
	{
		*top_a = sa(*top_a);
	}
	else if(i == 1)
	{
		if(is_sorted(*top_a = ra(*top_a)) == 0)	
			sa(*top_a);
	}
}
void update_poses(t_list *stack, int is_b)
{
	int i;
	int size;
	t_list *ptr;

	i = 0;
	ptr = stack;
	size = ft_lstsize(stack);
	while(ptr)
	{
		ptr -> pos = i++;
		if(!is_b)
			ptr -> target_pos = ptr -> index - 1;	
		ptr = ptr -> next;
	}

}

void push_2b(t_list **top_a, t_list **top_b, int size_a)
{
	int i;

	i = size_a - 3;
	while(i)
	{
		if ((*top_a) -> index < (size_a / 2))
		{
			// *top_b = pb(*top_a,)
		}
		
	}
}

int main(int ac, char *av[])
{
	char **arr ;
	t_list *top_a;
	// t_list *top_b;

	if(ac < 2)
		ft_clear(0, 0, 0, 1);
	arr = to_arr(ac, av);
	top_a = stock_args(arr);
	print_content(top_a);
	if(is_sorted(top_a))
		return(ft_clear(&top_a, 0, 0, 0),1);
	else if(ft_lstsize(top_a) == 2)
		return(ft_printf("sa\n"),ft_clear(&top_a, 0, 0, 0), 1);
	else if (ft_lstsize(top_a) == 3)
		handle_3num(&top_a);
	else if (ft_lstsize(top_a) > 3)
	{

	}
		
}
