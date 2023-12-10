#include "lib.h"

char	*_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc((_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
