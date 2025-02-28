/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:16:34 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 20:13:38 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lstlast_bonus(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}

void	ft_lstadd_back_bonus(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new -> next = NULL;
		return ;
	}
	ptr = ft_lstlast_bonus(*lst);
	ptr -> next = new;
	new -> next = NULL;
}

void	ft_clear_bonus(t_list **lst, char **arr, int quit)
{
	t_list	*ptr;
	t_list	*tmp;
	int		i;

	i = 0;
	if (lst)
		ptr = *lst;
	while (lst && ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	if (lst)
		*lst = NULL;
	if (arr)
		while (arr[i])
			free(arr[i++]);
	if (arr)
		free(arr);
	if (quit)
	{
		ft_printf_bonus("Error\n", 2);
		exit(1);
	}
}

int	ft_lstsize_bonus(t_list *lst)
{
	t_list	*ptr;
	int		count;

	ptr = lst;
	count = 0;
	while (ptr)
	{
		ptr = ptr -> next;
		count++;
	}
	return (count);
}

t_list	*get_beflast_bonus(t_list *lst)
{
	t_list	*ptr;

	if (!lst || !(lst -> next))
		return (NULL);
	ptr = lst;
	while (ptr -> next -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}
