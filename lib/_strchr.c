#include "lib.h"

int		_strchr(char *str, char c)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i] != '\0')
		if (str[i] == c)
			return (i);
	return (-1);
}
