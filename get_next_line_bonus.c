/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:34:32 by rbrune        #+#    #+#                 */
/*   Updated: 2021/12/14 11:34:33 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	newline(char *buff)
{
	int		i;
	int		s_len;

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
	static char	buff[OPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	nxt_line = ft_strdup(buff[fd]);
	if (nxt_line == NULL)
		return (NULL);
	while (newline(buff[fd]))
	{
		read_size = read(fd, buff[fd], BUFFER_SIZE);
		if (read_size == -1)
			return (return_check(nxt_line));
		buff[fd][read_size] = '\0';
		nxt_line = ft_strjoin(nxt_line, buff[fd], read_size);
		if (nxt_line == NULL)
			return (NULL);
		if (read_size != BUFFER_SIZE)
			break ;
	}
	nxt_line = before_newline(nxt_line);
	after_newline(buff[fd]);
	return (return_check(nxt_line));
}
