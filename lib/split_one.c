#include "lib.h"

char	**split_one(char *str, char c)
{
	char	**data;
	int		i;

	data = (char **)malloc(sizeof(char *) * 3);
	i = _strchr(str, c);
	data[0] = _strndup(str, i);
	data[1] = _strdup(str + i + 1);
	data[2] = NULL;
	return (data);
}
