#include "get_next_line_bonus.h"

char	*return_check(char *nxtLine)
{
	if (nxtLine && nxtLine[0])
		return (nxtLine);
	else
	{
		free(nxtLine);
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

char	*ft_strjoin(char *s1, char *s2, int readRet)
{
	char	*ret;
	int		j;
	int		k;
	int		sLen;

	j = 0;
	k = 0;
	sLen = ft_strlen(s1);
	ret = malloc(sLen + readRet + 1);
	if (!ret)
		return (return_check(s1));
	while (j < sLen)
	{
		ret[j] = s1[j];
		j++;
	}
	while (k < readRet && s2[k])
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
	int		sLen;

	i = 0;
	sLen = ft_strlen(s1);
	s1cpy = malloc(sLen + 1);
	if (!s1cpy)
		return (0);
	while (i < sLen)
	{
		s1cpy[i] = s1[i];
		i++;
	}
	s1cpy[i] = '\0';
	return (s1cpy);
}
