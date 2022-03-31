/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiha <jiha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:01:35 by jiha              #+#    #+#             */
/*   Updated: 2022/03/30 16:17:56 by jiha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_return_val(char **check)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	while (*check[i] && *check[i] != '\n')
		i++;
	if (*check[i] == '\n')
	{
		i++;
		line = ft_substr(*check, 0, i);
		tmp = ft_strdup(*check + i);
		free(*check);
		*check = tmp;
		return (line);
	}
	line = ft_strdup(*check);
	free(*check);
	*check = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*check[MAX_FD];
	char		*return_val;
	int			nbytes;
	char		buf[BUFFER_SIZE + 1];

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0 && (!ft_strchr(check[fd], '\n')))
	{
		buf[nbytes] = '\0';
		if (!check[fd])
			check[fd] = ft_strdup("");
		check[fd] = ft_strjoin(check[fd], buf);
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
	return_val = ft_get_return_val(&check[fd]);
	return (return_val);
}
