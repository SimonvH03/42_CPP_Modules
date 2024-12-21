#include "get_next_line.h"

void	*ft_free_null(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

int	ft_strlen_null(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	ft_strchr_null(const char *str, char c)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] || str[i] == c)
			if (str[i++] == c)
				return (i);
	return (0);
}

void	ft_bzero(char *src, size_t n)
{
	if (src)
		while (n--)
			((char *)src)[n] = 0;
}
