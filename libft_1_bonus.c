/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:03:48 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/27 18:05:54 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlcat_bonus(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!dst && !dstsize)
		return (ft_strlen_bonus((char *)src));
	i = ft_strlen_bonus(dst);
	if (dstsize < i + 1)
		return (ft_strlen_bonus((char *)src) + dstsize);
	j = 0;
	while ((dstsize > i + 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	return (i + ft_strlen_bonus((char *)src) - j);
}

char	*ft_strdup_bonus(const char *s1)
{
	char	*c;
	size_t	l;

	l = ft_strlen_bonus((char *) s1);
	c = (char *) malloc(l + 1);
	if (!c)
		return (NULL);
	ft_strlcpy_bonus(c, s1, l + 1);
	return (c);
}

void	ft_printf_bonus(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen_bonus(s));
}

size_t	ft_strlcpy_bonus(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_bonus((char *)src);
	if (!dstsize)
		return (src_len);
	while ((i < dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

int	is_sorted_bonus(t_list *top_a)
{
	int	last;

	last = INT_MIN;
	while (top_a)
	{
		if ((top_a -> content) < last)
			return (0);
		last = top_a -> content;
		top_a = top_a -> next;
	}
	return (1);
}
