/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:34:53 by rbrune        #+#    #+#                 */
/*   Updated: 2021/12/14 11:35:30 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int read_size);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);
char	*return_check(char *nxt_line);
void	after_newline(char *str);
char	*before_newline(char *nxt_line);

#endif