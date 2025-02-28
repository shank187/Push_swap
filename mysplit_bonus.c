/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysplit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:23:17 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 18:26:33 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	skip_seps_bonus(size_t *i, char const *s, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
}

static size_t	count_cols_bonus(char const *s, char c)
{
	size_t	t;
	size_t	i;

	t = 0;
	i = 0;
	if (!s[i])
		return (0);
	skip_seps_bonus(&i, s, c);
	while (s[i])
	{
		if (s[i] == c)
		{
			skip_seps_bonus(&i, s, c);
			t++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		t++;
	return (t);
}

static int	check_crash_bonus(char **arr, size_t i)
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

static int	ft_store_bonus(char **arr, const char *s, char c, size_t cols)
{
	size_t	i;
	size_t	j;
	size_t	l;

	j = 0;
	i = 0;
	skip_seps_bonus(&i, s, c);
	l = i;
	while (j < cols)
	{
		if (s[i] == c || !s[i])
		{
			arr[j] = ft_substr_bonus(s, l, i - l);
			if (!check_crash_bonus(arr, j))
				return (0);
			skip_seps_bonus(&i, s, c);
			l = i;
			j++;
		}
		else
			i++;
	}
	return (1);
}

char	**ft_split_bonus(char *s, char c)
{
	size_t	cols;
	char	**arr;

	if (!s)
		return (ft_clear_bonus(0, 0, 1), NULL);
	cols = count_cols_bonus(s, c);
	arr = (char **)malloc((cols + 1) * sizeof(char *));
	if (!arr)
		return (free(s), NULL);
	arr[cols] = NULL;
	if (cols)
	{
		if (ft_store_bonus(arr, s, c, cols))
			return (free(s), arr);
		else
			return (free(s), NULL);
	}
	return (free(s), arr);
}
