/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:34:51 by rbrune        #+#    #+#                 */
/*   Updated: 2021/12/15 11:10:36 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int readRet);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*return_check(char *nxtLine);
void	after_newline(char *str);
char	*before_newline(char *nxtLine);

#endif