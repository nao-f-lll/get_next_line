/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:39:20 by nlyamani          #+#    #+#             */
/*   Updated: 2025/01/25 16:49:29 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*trim_stash(char **stash)
{
	int		i;
	char	*line;
	char	*new_stash;

	i = 0;
	if (!*stash)
		return (NULL);
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stash, i + 2);
	if (!(*stash)[i])
		return (free(*stash), *stash = NULL, line);
	new_stash = ft_strdup(*stash + i + 1);
	if (!new_stash)
		return (free(line), free(*stash), *stash = NULL, NULL);
	if (*stash)
		free(*stash);
	*stash = new_stash;
	return (line);
}

char	*fill_stash(int fd, char *buf, char **stash)
{
	int		num_read;
	char	*temp;

	num_read = 1;
	while (num_read > 0 && !ft_strchr(stash[fd], '\n'))
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read > 0)
		{
			buf[num_read] = '\0';
			temp = stash[fd];
			stash[fd] = ft_strjoin(stash[fd], buf);
			free(temp);
		}
	}
	return (stash[fd]);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		buf[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	if (!stash[fd])
		stash[fd] = (char *) ft_calloc(1, sizeof(char));
	if (!stash[fd])
		return (NULL);
	buf[0] = '\0';
	stash[fd] = fill_stash(fd, buf, stash);
	if (!stash[fd] || *stash[fd] == '\0')
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = trim_stash(&stash[fd]);
	if (stash[fd] && *stash[fd] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
/*
int 	main(int argc, char **argv)
{
      if (argc < 2)
        return (1);
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);
    int fd3 = open(argv[3], O_RDONLY);
    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
        return (1);
    
    char *line;
    while (1)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("fd1: %s", line);
            free(line);
        }
        line = get_next_line(fd2);
        if (line)
        {
            printf("fd2: %s", line);
            free(line);
        }
        line = get_next_line(fd3);
        if (line)
        {
            printf("fd3: %s", line);
            free(line);
        }
        if (!line)
            break;
    }
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}
*/
