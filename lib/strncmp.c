#include "lib.h"

int		strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	i = 0;
	if (num == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] && str2[i] && i < num - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
