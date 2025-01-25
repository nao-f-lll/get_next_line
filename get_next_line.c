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

char	*ft_clean(char *stash, int i) 
{
	char  *temp = ft_calloc(ft_strlen(stash + i + 1) + 2, sizeof(char));
	int j = 0;
	while (stash[i + 1 + j] != '\0')
	{
		temp[j] = stash[i + 1 + j];
		j++;
	}
	free(stash);
	return (temp);
}

char	*trim_stash(char *stash, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!stash)
		return NULL;
	while (stash[i] != '\n')
		i++;
	while (stash[i + j] != '\0')
		j++;
	
	line = (char *) ft_calloc(ft_strlen(stash) - j + 2, sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 2);
	//stash = ft_clean(stash, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char *stash = NULL;
	char	*line;
	char	buf[BUFFER_SIZE];
	int		num_read;
	
	if (BUFFER_SIZE <= 0 && fd == -1)
		return (NULL);
	num_read = BUFFER_SIZE;
	if (!stash)
		stash =(char *) ft_calloc(1, sizeof(char));
	if (!stash)
		return (NULL);
	while (BUFFER_SIZE == num_read && !ft_strchr(stash, '\n'))
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		buf[num_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	if(stash[0] == '\0')
	{
		line = NULL;
		return (free(stash), line);
		
	}
	line = trim_stash(stash, line);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd = open(argv[1], O_RDONLY);
	char *line;
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
			//printf("%s", line);
	}
	free(line);
	close(fd);
	return (0);
}
