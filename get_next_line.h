/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiha <jiha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:02:05 by jiha              #+#    #+#             */
/*   Updated: 2022/03/30 16:16:52 by jiha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *c);
char	*ft_read_str(int fd, char *check);
char	*ft_get_return_val(char *check);
char	*ft_new_check(char *check, char *return_val);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);

#endif