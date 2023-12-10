#include "lib.h"

int		count_s(char const *s, char c)
{
	int value;
	int i;
	int j;

	value = 0;
	i = 0;
	j = _strlen(s);
	while (s[i] == c && s[i])
		i++;
	while (s[j] && s[j] == c && j > 0)
		j--;
	if (i > j)
		return (0);
	while (i <= j)
	{
		if (s[i] != c)
			i++;
		else
		{
			while (s[i] == c)
				i++;
			value++;
		}
	}
	return (value);
}

char	**free_func(char **data, int i)
{
	while (i >= 0)
	{
		free(data[i]);
		data[i--] = NULL;
	}
	free(data);
	data = NULL;
	return (NULL);
}

char	**split(char const *s, char c)
{
	char	**data;
	int		i;
	int		size;

	if (!s || !(data = (char **)malloc(sizeof(char *) * (count_s(s, c) + 2))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			size = 0;
			while (*(s + size) != c && *(s + size))
				size++;
			if (!(data[i] = substr(s, 0, size)))
				return (free_func(data, i));
			s += size;
			i++;
		}
	}
	data[i] = NULL;
	return (data);
}
