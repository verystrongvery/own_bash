#include "lib.h"

char	**copy_2d_arr(char **arr, int size)
{
	char	**ret;
	int		except;
	int		i;
	int		j;

	if (size == AUTO_SIZE)
		while (arr[size])
			size++;
	if (size == '_')
	{
		except = 1;
		size = MAX;
	}
	ret = (char**)malloc(sizeof(char*) * (size + 1));
	i = -1;
	j = -1;
	while (++i < size && arr[i])
		if (!(except == 1 && !strncmp(arr[i], "_=", 2)))
			ret[++j] = _strdup(arr[i]);
	ret[++j] = 0;
	return (ret);
}
