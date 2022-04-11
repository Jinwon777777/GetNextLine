/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiha <jiha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:46:22 by jiha              #+#    #+#             */
/*   Updated: 2022/04/08 12:46:44 by jiha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

char	*ft_get_return_val(char **check)
{
	char	*line;
	int		i;
	char	*tmp;

	i = 0;
	while ((*check)[i] && (*check)[i] != '\n')
		i++;
	if ((*check)[i] == '\n')
	{
		line = ft_substr(*check, 0, i + 1);
		tmp = ft_strdup(*check + i + 1);
		free(*check);
		*check = tmp;
		if (!**check)
		{
			free(*check);
			*check = NULL;
		}
		return (line);
	}
	line = ft_strdup(*check);
	free(*check);
	*check = NULL;
	return (line);
}

int	ft_put_line(char **check, int fd)
{
	char	*tmp;
	int		nbytes;
	char	buf[BUFFER_SIZE + 1];

	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buf[nbytes] = '\0';
		if (!check[fd])
			check[fd] = ft_strdup("");
		tmp = ft_strjoin(check[fd], buf);
		free(check[fd]);
		check[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
	return (nbytes);
}

char	*get_next_line(int fd)
{
	static char	*check[MAX_FD];
	char		*return_val;
	int			nbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nbytes = ft_put_line(check, fd);
	if ((nbytes < 0) || ((nbytes == 0) && (!check[fd] || !*check[fd])))
		return (NULL);
	return_val = ft_get_return_val(&check[fd]);
	return (return_val);
}
