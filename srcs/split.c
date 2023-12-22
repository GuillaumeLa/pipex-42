
#include "../includes/pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	theoric_len;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size <= start)
		return (ft_strdup(""));
	theoric_len = size - start;
	if (theoric_len > len)
		theoric_len = len;
	new_str = (char *)malloc((theoric_len + 1) * sizeof(char));
	if (!new_str)
		return (0);
	i = start;
	j = 0;
	while (i < size && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

static void	ft_parse_words(char **result, char const *str, char sep)
{
	char const	*buffer;

	buffer = str;
	while (*buffer)
	{
		while (*str == sep)
			++str;
		buffer = str;
		while (*buffer && *buffer != sep)
			++buffer;
		if (*buffer == sep || buffer > str)
		{
			*result = ft_substr(str, 0, buffer - str);
			str = buffer;
			++result;
		}
	}
	*result = NULL;
}

static int	ft_get_words(char const *str, char sep)
{
	int	words_len;

	words_len = 0;
	while (*str)
	{
		while (*str == sep)
			++str;
		if (*str)
			++words_len;
		while (*str && *str != sep)
			++str;
	}
	return (words_len);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_get_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_parse_words(new, s, c);
	return (new);
}
char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!str && n == 0)
		return (0);
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i != n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) != n)
		{
			j++;
			if (!to_find[j])
				return ((char *)str + i);
		}
		i++;
	}
	return (0);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_new;
	int		i;
	int		j;
	char	*result;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	size_new = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *) malloc((size_new +1) * sizeof(char));
	if (result == NULL)
		return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	return (result);
}

