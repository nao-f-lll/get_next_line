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

#define BUF_SIZE 3

void	read_to_buf_size(int fd)
{
	char *buf = (char*) malloc(BUF_SIZE * sizeof(char));
	static char  *stash;
	ssize_t num_read = read(fd, buf, BUF_SIZE);
	stash = ft_strdup(buf);
	while (read(fd, buf, BUF_SIZE) > 0)
		stash = ft_strjoin(stash, buf);	
	printf("%s", stash);
	free(buf);
}

char	*get_next_line(int fd)
{
	read_to_buf_size(fd);
	return (NULL);
}

int	main(void)
{
	int	fd = open("file1.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
	return (0);
}
