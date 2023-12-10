#include "lib.h"

void	free_2d_arr(char **arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	free_3d_arr(char ***arr)
{
	int i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free_2d_arr(arr[i]);
	free(arr);
}

void	free_init(char **data, char *init)
{
	free(*data);
	*data = init;
}
