/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/14 11:34:39 by rbrune        #+#    #+#                 */
/*   Updated: 2021/12/14 11:36:12 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*return_check(char *nxt_line)
{
	if (nxt_line && nxt_line[0])
		return (nxt_line);
	else
	{
		free(nxt_line);
		return (NULL);
	}
}

void	after_newline(char *str)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str[j] != '\n' && j < ft_strlen(str))
		j++;
	j++;
	while (k < ft_strlen(str) - j)
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
