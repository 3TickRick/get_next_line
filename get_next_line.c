#include "get_next_line.h"

int	newline(char *buff)
{
	int		i;
	int		sLen;

	i = 0;
	sLen = ft_strlen(buff);
	while (i < sLen)
	{
		if (buff[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*before_newline(char *nxtLine)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nxtLine[i] != '\n' && nxtLine[i])
		i++;
	i++;
	str = malloc(i + 1);
	if (!str)
	{
		free (nxtLine);
		return (NULL);
	}
	while (j < i)
	{
		str[j] = nxtLine[j];
		j++;
	}
	str[j] = '\0';
	free (nxtLine);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*nxtLine;
	int			readSize;
	static char	buff[BUFFER_SIZE + 1];

	nxtLine = ft_strdup(buff);
	if (nxtLine == NULL)
		return (NULL);
	while (newline(buff))
	{
		readSize = read(fd, buff, BUFFER_SIZE);
		if (readSize == -1)
			return (return_check(nxtLine));
		buff[readSize] = '\0';
		nxtLine = ft_strjoin(nxtLine, buff, readSize);
		if (nxtLine == NULL)
			return (NULL);
		if (readSize != BUFFER_SIZE)
			break ;
	}
	nxtLine = before_newline(nxtLine);
	if (nxtLine == NULL)
		return (NULL);
	after_newline(buff);
	return (return_check(nxtLine));
}
