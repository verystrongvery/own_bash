#include "lib.h"

char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*data;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = -1;
	data = (char *)malloc((sizeof(char) * len) + 1);
	if (data == NULL)
		return (NULL);
	if (_strlen(s) < (int)start)
	{
		data[0] = '\0';
		return (data);
	}
	while (++i < len)
		data[i] = s[start++];
	data[i] = '\0';
	return (data);
}
