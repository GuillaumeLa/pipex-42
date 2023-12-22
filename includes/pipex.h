#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);
char	**ft_split(char const *s, char c);
#endif