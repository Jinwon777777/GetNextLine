/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiha <jiha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:02:21 by jiha              #+#    #+#             */
/*   Updated: 2022/03/30 16:19:58 by jiha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (strlen(s1) + 1));
	if (!(tmp))
		return (NULL);
	while (s1[i])
	{
		s1[i] = tmp[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	if (!(s2))
		return (NULL);
	if (!(s1))
	{
		s1 = (char *)malloc(sizeof(char) * (1));
		s1[0] = '\0';
	}
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(arr))
		return (NULL);
	i = -1;
	while (s1[++i])
		arr[i] = s1[i];
	j = -1;
	while (s2[++j])
		arr[i + j] = s2[j];
	arr[i + j] = '\0';
	free(s1);
	return (arr);
}
