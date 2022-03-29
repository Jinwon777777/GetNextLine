/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiha <jiha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:02:05 by jiha              #+#    #+#             */
/*   Updated: 2022/03/29 10:53:01 by jiha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *c);
char	*ft_read_str(int fd, char *check);
char	*ft_get_return_val(char *check);
char	*ft_new_check(char *check, char *return_val);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif