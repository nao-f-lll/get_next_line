/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:34:41 by nlyamani          #+#    #+#             */
/*   Updated: 2025/01/25 13:35:08 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			al_s;
	size_t			index;

	al_s = nmemb * size;
	tmp = (unsigned char *) malloc(al_s);
	if (!tmp)
		return (NULL);
	index = 0;
	while (index < al_s)
		((char *) tmp)[index++] = '\0';
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t		index;

	index = 0;
	while (s[index])
		index++;
	return (index);
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

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	int		s1_s;
	int		i;

	i = 0;
	s1_s = ft_strlen(s1);
	s1_dup = (char *) malloc((s1_s + 1) * sizeof(char));
	if (!s1_dup)
		return (NULL);
	while (i < s1_s)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}
