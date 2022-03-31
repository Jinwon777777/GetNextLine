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

char	*ft_read_str(int fd, char **check)
{
	int		nbytes;
	char	buf[BUFFER_SIZE + 1];

	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0 && (!ft_strchr(check[fd], '\n')))
	{
		buf[nbytes] = '\0';
		if (nbytes == -1)
		{
			free(buf);
			return (NULL);
		}
		if (!check[fd])
			check[fd] = ft_strdup("");
		check[fd] = ft_strjoin(check[fd], buf);
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
	return (check);
}

char	*ft_get_return_val(char *check)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (check[i] && check[i] != '\n')
		i++;
	if (check[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = -1;
	while (i > ++j)
		line[j] = check[j];
	line[j] = '\0';
	return (line);
}

char	*ft_new_check(char *check, char *return_val)
{
	int		i;
	int		j;
	char	*arr;

	i = ft_strlen(return_val);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(check) - i + 1));
	if (!arr)
		return (NULL);
	j = 0;
	while (check[i] != '\0')
	{
		arr[j] = check[i + j];
		j++;
	}
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*check[MAX_FD];
	char		*return_val;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	check = ft_read_str(fd, check);
	if (!check)
		return (NULL);
	return_val = ft_get_return_val(check);
	check = ft_new_check(check, return_val);
	return (return_val);
}
