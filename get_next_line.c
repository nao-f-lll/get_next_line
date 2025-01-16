/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlyamani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:39:20 by nlyamani          #+#    #+#             */
/*   Updated: 2024/12/04 16:47:18 by nlyamani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 4

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
	
	line = (char *) ft_calloc(ft_strlen(stash) - j + 1, sizeof(char));
	ft_strlcpy(line, stash, i + 1);	
	ft_strlcpy(stash, stash + i + 1, i + j + 1);

	return (line);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char	*line;
	char	buf[BUF_SIZE];
	int	num_read;
	
	num_read = 1;
	if (!stash)
		stash =(char *) ft_calloc(1, sizeof(char));

	while (0 < num_read && !ft_strchr(stash, '\n'))
	{
		num_read = read(fd, buf, BUF_SIZE);
		buf[num_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}	
	line = trim_stash(stash, line);
	printf("%s \n", line);
	return (line);
}

int	main(int argc, char **argv)
{
	int counter = 5;
	int	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		while(counter > 0)
		{
			get_next_line(fd);
			counter--;
		}
	}
	else 
		printf("Error");
	close(fd);
	return (0);
}
