/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:44:19 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/08 21:06:28 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*c;
	size_t	size;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *) s);
	if (start > s_len)
		return (ft_strdup(""));
	s_len = ft_strlen((char *) &s[start]);
	size = len + 1;
	if (s_len < len)
		size = s_len + 1;
	c = (char *) malloc(size);
	if (!c)
		return (NULL);
	ft_strlcpy(c, &s[start], size);
	return (c);
}
 
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	siz;
	char	*c;
	siz = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	c = (char *) malloc(siz);
	if (!c)
	{
		free(s1);
		return (NULL);
	}
	c[0] = 0;
	if (s1)
		ft_strlcat(c, s1, ft_strlen((char *) s1) + 1);
	ft_strlcat(c, s2, siz);
	free(s1);
	return (c);
}

static void	ft_get_sign(int *s, long *i, const char *str)
{
	*s = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*s = -1;
		(*i)++;
	}
}

long	ft_atoi(const char *str)
{
	long	i;
	long	t;
	long	oldt;
	int		s;

	t = 0;
	oldt = 0;
	i = 0;
	ft_get_sign(&s, &i, str);
	if(!str[i])
		return(2147483649);
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return( 2147483649);
		t = (t * 10) + (str[i++] - '0');
		if ((t / 10) != oldt && s < 0)
			return (2147483649);
		else if ((t / 10) != oldt && s > 0)
			return (2147483649);
		oldt = t;
	}
	return (t * s);
}
