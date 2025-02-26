/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:24:37 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/26 08:48:59 by aelbour          ###   ########.fr       */
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
		new -> next = NULL;
		return;
	}
	ptr = ft_lstlast(*lst);
	ptr -> next = new;
	new -> next = NULL;
}

void	ft_clear(t_list **lst, char **arr, char *s, int quit)
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
		free(ptr);
		ptr = tmp;
	}
	if(lst)
		*lst = NULL;
	if(s)
		free(s);
	if(arr)
		while(arr[i])
			free(arr[i++]);
	if(arr)
		free(arr);
	if(quit)
	{
		ft_printf("Error\n",0);
		exit(1);		
	}
}

int ft_lstsize(t_list *lst)
{
	t_list *ptr;
	int count;

	ptr = lst;
	count = 0;
	while(ptr)
	{
		ptr = ptr -> next;
		count++;
	}
	return(count);
}

t_list *get_beflast(t_list *lst)
{
	t_list *ptr;

	if(!lst || !(lst -> next))
		return (NULL);
	ptr = lst;
	while((ptr -> next )-> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}

