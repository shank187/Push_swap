/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:56:58 by aelbour           #+#    #+#             */
/*   Updated: 2025/03/01 15:53:08 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *ptr)
{
	int	max;
	int	val;

	max = 0;
	val = 0;
	while (ptr)
	{
		if ((ptr -> index) > max)
		{
			max = ptr -> index;
			val = ptr -> content;
		}
		ptr = ptr -> next;
	}
	return (val);
}

void	push_2b(t_list **top_a, t_list **top_b, int size_a)
{
	int	i;

	i = 1;
	while (i < size_a / 2)
	{
		if ((*top_a)-> index < size_a / 2)
		{
			pb(top_a, top_b, 1);
			i++;
		}
		else
			ra(top_a, 1);
	}
	while (i <= size_a - 3)
	{
		pb(top_a, top_b, 1);
		i++;
	}
	handle_3num(top_a);
}

void	sort_all(t_list **top_a, t_list **top_b)
{
	int	a;
	int	b;
	int	choose;

	push_2b(top_a, top_b, ft_lstsize(*top_a));
	a = 0;
	b = 0;
	while (ft_lstsize(*top_b))
	{
		update_infos(*top_a, *top_b);
		best_smoves(*top_b, &a, &b);
		push_target(top_a, top_b, a, b);
	}
	choose = rr_or_rrr(*top_a);
	while (!is_sorted(*top_a))
	{
		if (choose)
			ra(top_a, 1);
		else
			rra(top_a, 1);
	}
}

void	handle_3num(t_list **top_a)
{
	int		i;
	int		max_val;
	t_list	*ptr;

	ptr = *top_a;
	i = 0;
	max_val = get_max(ptr);
	while (ptr && ++i && ptr -> content != max_val)
		ptr = ptr -> next;
	if (i == 2 && !is_sorted(*top_a))
	{
		rra(top_a, 1);
		if (is_sorted(*top_a) == 0)
			sa(top_a, 1);
	}
	else if (i == 3 && !is_sorted(*top_a))
	{
		sa(top_a, 1);
	}
	else if (i == 1 && !is_sorted(*top_a))
	{
		ra(top_a, 1);
		if (is_sorted((*top_a)) == 0)
			sa(top_a, 1);
	}
}

int	main(int ac, char *av[])
{
	char	**arr ;
	t_list	*top_a;
	t_list	*top_b;

	top_b = NULL;
	if (ac < 2)
		return (0);
	arr = to_arr(ac, av);
	if (!arr)
		return (ft_clear(0, 0, 1), 0);
	top_a = stock_args(arr);
	if (is_sorted(top_a))
		return (ft_clear(&top_a, 0, 0), 1);
	else if (ft_lstsize(top_a) == 2)
		return (ft_printf("sa\n", 1), ft_clear(&top_a, 0, 0), 1);
	else if (ft_lstsize(top_a) == 3)
		handle_3num(&top_a);
	else if (ft_lstsize(top_a) == 5)
		handle_5num(&top_a, &top_b);
	else if (ft_lstsize(top_a) > 3)
		sort_all(&top_a, &top_b);
	ft_clear(&top_a, 0, 0);
}
