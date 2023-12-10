#include "lib.h"

char	*_strndup(char *str, int size)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char*)malloc(sizeof(char) * (size + 1));
	while (++i < size)
		ret[i] = str[i];
	ret[size] = '\0';
	return (ret);
}
