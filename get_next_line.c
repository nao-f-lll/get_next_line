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

#include "get_next_line.h"

char	*trim_stash(char **stash)
{
	int	i;

	i = 0;
	if (!*stash)
		return NULL;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	char *line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stash, i + 2);
    	if (!(*stash)[i])
		return (free(*stash), *stash = NULL, line);
	char *new_stash = ft_strdup(*stash + i + 1);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int		num_read;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!stash)
		stash = (char *) ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL); 
	num_read = 1;
	while (num_read > 0 && !ft_strchr(stash, '\n'))
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read > 0)
		{
		buf[num_read] = '\0';
		char *temp = stash;
		stash = ft_strjoin(stash, buf);
		free(temp);
		}
	}
	 if (!stash || *stash == '\0')
        	return (free(stash), stash = NULL, NULL);
	line = trim_stash(&stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
       		stash = NULL;
	}
	return (line);
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return 1;
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
