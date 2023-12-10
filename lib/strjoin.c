#include "lib.h"

char	*strjoin(char const *s1, char const *s2)
{
	char	*data;
	int		size;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = _strlen(s1) + _strlen(s2);
	i = -1;
	j = -1;
	data = (char *)malloc(sizeof(char) * size + 1);
	if (data == NULL)
		return (NULL);
	while (s1[++i])
		data[i] = s1[i];
	while (s2[++j])
		data[i + j] = s2[j];
	data[i + j] = '\0';
	return (data);
}
