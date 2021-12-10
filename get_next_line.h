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