/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:33:48 by rbrune        #+#    #+#                 */
/*   Updated: 2021/12/15 12:11:36 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline(char *buff)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(buff);
	while (i < s_len)
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*before_newline(char *nxt_line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nxt_line[i] != '\n' && nxt_line[i])
		i++;
	i++;
	str = malloc(i + 1);
	if (!str)
	{
		free (nxt_line);
		return (NULL);
	}
	while (j < i)
	{
		str[j] = nxt_line[j];
		j++;
	}
	str[j] = '\0';
	free (nxt_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*nxt_line;
	int			read_size;
	static char	buff[BUFFER_SIZE + 1];

	nxt_line = ft_strdup(buff);
	if (nxt_line == NULL)
		return (NULL);
	while (newline(buff))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
			return (return_check(nxt_line));
		buff[read_size] = '\0';
		nxt_line = ft_strjoin(nxt_line, buff, read_size);
		if (nxt_line == NULL)
			return (NULL);
		if (read_size != BUFFER_SIZE)
			break ;
	}
	nxt_line = before_newline(nxt_line);
	if (nxt_line == NULL)
		return (NULL);
	after_newline(buff);
	return (return_check(nxt_line));
}
