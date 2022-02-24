/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:28:16 by chpark            #+#    #+#             */
/*   Updated: 2022/02/24 10:54:38 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t		i;
	char		*s;

	s = (char *)malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strnjoin(char *s1, char const *s2, ssize_t n)
{
	char	*s;
	int		l1;

	if (!s1)
		return (ft_strndup(s2, -1));
	l1 = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (l1 + n + 1));
	if (!s)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(s, s1, l1 + 1);
	free(s1);
	ft_strlcpy(s + l1, s2, n + 1);
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sl;

	sl = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (sl);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sl);
}

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
