/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:24:37 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/08 19:54:10 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while(ptr -> next)
	{
		ptr = ptr -> next;
	}
	return(ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	ptr = ft_lstlast(*lst);
	ptr -> next = new;
}


void	ft_clear(t_list **lst, char **arr, char *s)
{
	t_list	*ptr;
	t_list	*tmp;
	int i;

	i = 0;
	if(lst)
		ptr = *lst;
	while (lst && ptr)
	{
		tmp = ptr->next;
		printf("freed node with value = %i\n",ptr -> content);
		free(ptr);
		ptr = tmp;
	}
	if(lst)
		*lst = NULL;
	if(s)
	{
		printf("freed string with value %s \n" ,s);
		free(s);
	}
	if(arr)
		while(arr[i])
		{
			printf("freed subs with value = %s\n",arr[i]);
			free(arr[i++]);
		}
	write(2, "Error\n" ,6);
	exit(1);
}

// void ft_lstiter(t_list *lst, void (*f)(void *))
// {
// 	t_list *ptr;

// 	if (!lst || !f)
// 		return;
// 	ptr = lst;
// 	while (ptr)
// 	{
// 		f(ptr->content);
// 		ptr = ptr->next;
// 	}
// }

