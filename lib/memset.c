#include "lib.h"

void	*memset(void *ptr, int value, size_t num)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)ptr;
	while (i < num)
	{
		str[i] = value;
		i++;
	}
	return (str);
}
