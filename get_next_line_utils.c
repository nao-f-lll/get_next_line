/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:34:41 by nlyamani          #+#    #+#             */
/*   Updated: 2024/12/02 17:35:46 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
		((char *) s)[index++] = c;
	return (s);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			al_s;

	al_s = nmemb * size;
	tmp = (unsigned char *) malloc(al_s);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, al_s);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (c > 255)
		c = c % 256;
	while (s[index])
	{
		if (s[index] == c)
			return ((char *)(s + index));
		index++;
	}
	if (c == '\0')
		return ((char *)(s + index));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t		index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (src == dest)
		return (dest);
	index = 0;
	while (index < n)
	{
		((char *)dest)[index] = ((char *)src)[index];
		index++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_s;
	int		s2_s;

	if (!s1 || !s2)
		return (NULL);
	s1_s = ft_strlen(s1);
	s2_s = ft_strlen(s2);
	str = (char *) malloc((s1_s + s2_s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1_s);
	ft_memcpy(str + s1_s, s2, s2_s);
	str[s1_s + s2_s] = '\0';
	return (str);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	if (size > 0)
	{
		index = 0;
		while (src[index] && index < size - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}
