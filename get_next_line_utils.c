/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:34:36 by rbrune        #+#    #+#                 */
/*   Updated: 2021/12/15 12:11:55 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_check(char *next_line)
{
	if (next_line && next_line[0])
		return (next_line);
	else
	{
		free(next_line);
		return (NULL);
	}
}

void	after_newline(char *str)
{
	int		j;
	int		k;
	int		s_len;

	j = 0;
	k = 0;
	s_len = ft_strlen(str);
	while (str[j] != '\n' && j < s_len)
		j++;
	j++;
	while (k < s_len - j)
	{
		str[k] = str[k + j];
		k++;
	}
	str[k] = '\0';
}

char	*ft_strjoin(char *s1, char *s2, int read_size)
{
	char	*ret;
	int		j;
	int		k;
	int		s_len;

	j = 0;
	k = 0;
	s_len = ft_strlen(s1);
	ret = malloc(s_len + read_size + 1);
	if (!ret)
		return (return_check(s1));
	while (j < s_len)
	{
		ret[j] = s1[j];
		j++;
	}
	while (k < read_size && s2[k])
	{
		ret[j] = s2[k];
		j++;
		k++;
	}
	ret[j] = '\0';
	free(s1);
	return (ret);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(char *s1)
{
	char	*s1cpy;
	int		i;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s1);
	s1cpy = malloc(s_len + 1);
	if (!s1cpy)
		return (0);
	while (i < s_len)
	{
		s1cpy[i] = s1[i];
		i++;
	}
	s1cpy[i] = '\0';
	return (s1cpy);
}
