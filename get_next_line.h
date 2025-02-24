/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbour <aelbour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:16:13 by aelbour           #+#    #+#             */
/*   Updated: 2025/02/24 15:56:04 by aelbour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_ln(char **s, char **l, int fd);
char	*get_next_line(int fd);
size_t	ft_strlcat2(char *dst, const char *src, size_t dstsize);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, char *s2, int is_s2_leak);
size_t	ft_strlen2(const char *s);
int		manage_prevs(char **s, char **l);
char	*xd(char **s, char **l, int j, int i);

#endif