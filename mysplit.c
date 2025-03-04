/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:27:39 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/26 12:02:17 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	skip_seps(size_t *i, char const *s, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
}

static size_t	count_cols(char const *s, char c)
{
	size_t	t;
	size_t	i;

	t = 0;
	i = 0;
	if (!s[i])
		return (0);
	skip_seps(&i, s, c);
	while (s[i])
	{
		if (s[i] == c)
		{
			skip_seps(&i, s, c);
			t++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		t++;
	return (t);
}

static int	check_crash(char **arr, size_t i)
{
	if (!arr[i])
	{
		while (i > 0)
		{
			i--;
			free(arr[i]);
		}
		free(arr);
		return (0);
	}
	return (1);
}

static int	ft_store(char **arr, const char *s, char c, size_t cols)
{
	size_t	i;
	size_t	j;
	size_t	l;

	j = 0;
	i = 0;
	skip_seps(&i, s, c);
	l = i;
	while (j < cols)
	{
		if (s[i] == c || !s[i])
		{
			arr[j] = ft_substr(s, l, i - l);
			if (!check_crash(arr, j))
				return (0);
			skip_seps(&i, s, c);
			l = i;
			j++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	size_t	cols;
	char	**arr;

	if (!s)
		return (ft_clear(0, 0, 1), NULL);
	cols = count_cols(s, c);
	arr = (char **)malloc((cols + 1) * sizeof(char *));
	if (!arr)
		return (free(s), NULL);
	arr[cols] = NULL;
	if (cols)
	{
		if (ft_store(arr, s, c, cols))
			return (free(s), arr);
		else
			return (free(s), NULL);
	}
	return (free(s), arr);
}
