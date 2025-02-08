/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:00:34 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/08 19:45:14 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_spcnum(char *s)
{
	size_t i;
	int valid;
	i = 0;
	valid = 0;
	while(s[i])
	{
		if(s[i] >=  '0' && s[i] <= '9')
			valid = 1;
		else if((s[i] < 48 || s[i] > 57) && s[i] != 32 && s[i] != 43 && s[i] != 45)
			return(0);
		i++;
	}
	return(valid);
}

char **to_arr(int ac, char *av[])
{
	size_t	i;
	char *s;

	s = ft_strjoin(ft_strdup(""),av[1]);
	i = 2;
	while(i < ac)
	{	if(!is_spcnum(av[i]))
			return(ft_clear(NULL, NULL, s),NULL);
		s = ft_strjoin(s, " ");
		if(!(s))
			return(ft_clear(NULL, NULL, s),NULL);
		(s) = ft_strjoin((s), av[i]);
		if(!(s))
			return(ft_clear(NULL, NULL, s),NULL);
		i++;
	}
	printf("string of args |%s|\n",s);
	return(ft_split(s,' '));
}

t_list *stock_args(char **arr)
{
	long i, n;
	t_list *node;
	t_list *top_a;
	
	top_a = NULL;
	node = NULL;
	i = 0;
	while(arr[i])
	{
		n = ft_atoi(arr[i]);
		printf("arr = %s num = %li\n",arr[i], n);
		if(n > INT_MAX || n < INT_MIN)
			return(ft_clear(&top_a, arr, NULL),NULL);
		node = malloc(sizeof(t_list *));
		if(!node)
			return(ft_clear(&top_a, arr, NULL), NULL);
		node -> content = n;
		ft_lstadd_back(&top_a, node);
		i++;
	}
	return top_a;
}

int main(int ac, char *av[])
{
	char **arr ;
	t_list *top_a;
	arr = to_arr(ac, av);
	top_a = stock_args(arr);

	print_content(top_a);

}